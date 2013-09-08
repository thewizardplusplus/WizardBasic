#include "parser/Parser.h"
#include "translator/Translator.h"
#include "parser/WizardBasicGrammar.h"
#include "exceptions/WizardBasicCompilerException.h"
#include <boost/spirit/home/classic/tree/tree_to_xml.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::parser;
using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::exceptions;

int main(void) {
	std::string code =
		"10 TEST(23)";

	try {
		Parser::ParseTree parse_tree = Parser().parse(code);
		tree_to_xml(std::cout, parse_tree, code, WizardBasicGrammarRule::NAMES);
		std::cout << std::endl;

		std::string cpp_code = Translator().translate(parse_tree);
		std::cout << cpp_code << std::endl;
	} catch (const WizardBasicCompilerException& exception) {
		std::cerr << exception.what() << std::endl;
	}
}
