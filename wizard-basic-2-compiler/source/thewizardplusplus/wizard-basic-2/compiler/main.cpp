#include "parser/Parser.h"
#include "parser/WizardBasicGrammarRule.h"
#include "translator/Translator.h"
#include "utils/os.h"
#include "compiler/Compiler.h"
#include "exceptions/WizardBasicCompilerException.h"
#include <boost/spirit/home/classic/tree/tree_to_xml.hpp>
#include <list>
#include <algorithm>
#include <fstream>

using namespace thewizardplusplus::wizard_basic_2::compiler::parser;
using namespace thewizardplusplus::wizard_basic_2::compiler::translator;
using namespace thewizardplusplus::wizard_basic_2::compiler::compiler;
using namespace thewizardplusplus::wizard_basic_2::compiler::exceptions;
using namespace boost;

int main(int number_of_arguments, char** arguments) {
	typedef std::list<std::string> OptionList;

	OptionList options;
	for (int i = 1; i < number_of_arguments; i++) {
		options.push_back(std::string(arguments[i]));
	}

	OptionList::const_iterator options_begin = options.begin();
	OptionList::const_iterator options_end = options.end();
	if (
		std::find(options_begin, options_end, "--version") != options_end
		|| std::find(options_begin, options_end, "-v") != options_end
	) {
		std::cout
			<< "Wizard BASIC 2 compiler, v1.0\n"
			<< "(c) thewizardplusplus, 2013-2015\n";

		return EXIT_SUCCESS;
	}

	if (
		std::find(options_begin, options_end, "--help") != options_end
		|| std::find(options_begin, options_end, "-h") != options_end
	) {
		std::cout
			<< "Using:\n"
			<< "\twb2c [options] [file]\n"
			<< "\n"
			<< "Options:\n"
			<< "\t-v, --version -   output version information;\n"
			<< "\t-h, --help -      output help information;\n"
			<< "\t-p, --parse -     stop process at parsing;\n"
			<< "\t-t, --translate - stop process at translating.\n";

		return EXIT_SUCCESS;
	}

	try {
		if (options.empty()) {
			throw WizardBasicCompilerException("don't specify input file");
		}
		std::string input_filename = options.back();
		if (
			input_filename.empty()
			|| input_filename == "--parse"
			|| input_filename == "-p"
			|| input_filename == "--translate"
			|| input_filename == "-t"
		) {
			throw WizardBasicCompilerException("don't specify input file");
		}

		std::ifstream in(input_filename.c_str());
		if (!in.is_open()) {
			throw WizardBasicCompilerException("unable to open input file");
		}
		std::string code(
			(std::istreambuf_iterator<char>(in)),
			std::istreambuf_iterator<char>()
		);
		in.close();

		Parser::ParseTree parse_tree = Parser().parse(code);
		if (
			std::find(options_begin, options_end, "--parse") != options_end
			|| std::find(options_begin, options_end, "-p") != options_end
		) {
			tree_to_xml(
				std::cout,
				parse_tree,
				code,
				WizardBasicGrammarRule::NAMES
			);

			return EXIT_SUCCESS;
		}

		std::string translated_code = Translator().translate(parse_tree);
		if (
			std::find(options_begin, options_end, "--translate") != options_end
			|| std::find(options_begin, options_end, "-t") != options_end
		) {
			std::cout << translated_code << std::endl;
			return EXIT_SUCCESS;
		}

		std::string compiler_path = arguments[0];
		#ifdef OS_LINUX
			size_t last_separator_index = compiler_path.rfind('/');
		#elif defined(OS_WINDOWS)
			size_t last_separator_index = compiler_path.rfind('\\');
		#endif
		if (last_separator_index != std::string::npos) {
			compiler_path = compiler_path.substr(0, last_separator_index);
		} else {
			compiler_path = ".";
		}
		#ifdef OS_LINUX
			compiler_path += "/";
		#elif defined(OS_WINDOWS)
			compiler_path += "\\";
		#endif

		std::string output_filename = input_filename;
		size_t extension_start_index = output_filename.rfind('.');
		if (extension_start_index != std::string::npos) {
			output_filename = output_filename.substr(0, extension_start_index);
		}

		Compiler().compile(translated_code, compiler_path, output_filename);
	} catch (const WizardBasicCompilerException& exception) {
		std::cerr << exception.what() << std::endl;
		return EXIT_FAILURE;
	}
}
