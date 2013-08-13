#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "../parser/Parser.h"
#include "Program.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class Translator {
public:
	std::string compile(const thewizardplusplus::wizard_basic::parser::Parser::
		ParseTree& parse_tree);

private:
	Program program;

	std::string getNodeValue(const thewizardplusplus::wizard_basic::parser::
		Parser::ParseTree::const_iterator& parse_tree_node) const;
	void compileLine(const thewizardplusplus::wizard_basic::parser::Parser::
		ParseTree::const_iterator& parse_tree_node);
	void compileStatement(const thewizardplusplus::wizard_basic::parser::Parser
		::Parser::ParseTree::const_iterator& parse_tree_node);
};

}
}
}
#endif
