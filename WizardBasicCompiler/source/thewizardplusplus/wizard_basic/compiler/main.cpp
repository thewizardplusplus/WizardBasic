#include "parser/Parser.h"
#include "parser/WizardBasicGrammarRule.h"
#include "translator/Translator.h"
#include "compiler/Compiler.h"
#include "exceptions/WizardBasicCompilerException.h"
#include <boost/spirit/home/classic/tree/tree_to_xml.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::parser;
using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::compiler;
using namespace thewizardplusplus::wizard_basic::compiler::exceptions;

int main(void) {
	std::string code =
		"5 DIM x[10]\n"
		"10 DIM NEW_LINE = \"\\n\"\n"
		"20 TRACEN(RND())\n"
		"30 TRACES(NEW_LINE)\n"
		"40 TRACEN(TIMER())\n"
		"50 TRACES(NEW_LINE)\n"
		"60 DIM TEST_STRING = \"Test.\"\n"
		"70 TRACES(TEST_STRING)\n"
		"80 TRACES(NEW_LINE)";

	try {
		Parser::ParseTree parse_tree = Parser().parse(code);
		tree_to_xml(std::cout, parse_tree, code, WizardBasicGrammarRule::NAMES);
		std::cout << std::endl;

		std::string translated_code = Translator().translate(parse_tree);
		std::cout << translated_code << std::endl;

		Compiler().compile(translated_code, "test");
	} catch (const WizardBasicCompilerException& exception) {
		std::cerr << exception.what() << std::endl;
	}
}
