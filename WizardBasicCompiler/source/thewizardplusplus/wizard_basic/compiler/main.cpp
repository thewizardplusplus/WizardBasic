#include "parser/Parser.h"
#include "parser/WizardBasicGrammarRule.h"
#include "translator/Translator.h"
#include "compiler/Compiler.h"
#include "exceptions/WizardBasicCompilerException.h"
#include <boost/spirit/home/classic/tree/tree_to_xml.hpp>
#include <list>
#include <algorithm>
#include <fstream>

using namespace thewizardplusplus::wizard_basic::compiler::parser;
using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::compiler;
using namespace thewizardplusplus::wizard_basic::compiler::exceptions;
using namespace boost;

int main(int number_of_arguments, char** arguments) {
	typedef std::list<std::string> OptionList;

	OptionList options;
	for (int i = 1; i < number_of_arguments; i++) {
		options.push_back(std::string(arguments[i]));
	}

	OptionList::const_iterator options_begin = options.begin();
	OptionList::const_iterator options_end = options.end();
	if (std::find(options_begin, options_end, "--version") != options_end || std
		::find(options_begin, options_end, "-v") != options_end)
	{
		std::cout <<
			"Wizard BASIC, v0.1.1.\n"
			"(c) 2013, thewizardplusplus.\n"
			<< std::endl;
		return EXIT_SUCCESS;
	}

	if (std::find(options_begin, options_end, "--help") != options_end || std::
		find(options_begin, options_end, "-h") != options_end)
	{
		std::cout <<
			"Using:\n"
			"\twbc [options] [file]\n"
			"\n"
			"Options:\n"
			"\t-v, --version -   output version information;\n"
			"\t-h, --help -      output help information;\n"
			"\t-p, --parse -     stop process at parsing;\n"
			"\t-t, --translate - stop process at translating.\n"
			<< std::endl;
		return EXIT_SUCCESS;
	}

	try {
		if (options.empty()) {
			throw WizardBasicCompilerException("don't specify input file");
		}
		std::string input_filename = options.back();
		if (input_filename.empty() || input_filename == "--parse" ||
			input_filename == "-p" || input_filename == "--translate" ||
			input_filename == "-t")
		{
			throw WizardBasicCompilerException("don't specify input file");
		}

		std::ifstream in(input_filename.c_str());
		if (!in.is_open()) {
			throw WizardBasicCompilerException("unable to open input file");
		}
		std::string code((std::istreambuf_iterator<char>(in)), std::
			istreambuf_iterator<char>());
		in.close();

		Parser::ParseTree parse_tree = Parser().parse(code);
		if (std::find(options_begin, options_end, "--parse") != options_end ||
			std::find(options_begin, options_end, "-p") != options_end)
		{
			tree_to_xml(std::cout, parse_tree, code, WizardBasicGrammarRule::
				NAMES);
			return EXIT_SUCCESS;
		}

		std::string translated_code = Translator().translate(parse_tree);
		if (std::find(options_begin, options_end, "--translate") != options_end
			|| std::find(options_begin, options_end, "-t") != options_end)
		{
			std::cout << translated_code << std::endl;
			return EXIT_SUCCESS;
		}

		std::string output_filename = input_filename;
		size_t index = output_filename.rfind('.');
		if (index != std::string::npos) {
			output_filename = output_filename.substr(0, index);
		}
		Compiler().compile(translated_code, output_filename);
	} catch (const WizardBasicCompilerException& exception) {
		std::cerr << exception.what() << std::endl;
	}
}
