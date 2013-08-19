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
	boost::shared_ptr<Program> program;

	std::string getNodeValue(const wizard_basic::parser::Parser::ParseTree::
		const_iterator& parse_tree_node) const;
	void compileLine(const wizard_basic::parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
	void compileStatement(const wizard_basic::parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
	void compileStatementArrayDefinition(const wizard_basic::parser::Parser::
		ParseTree::const_iterator& parse_tree_node);
};

}
}
}
#endif
