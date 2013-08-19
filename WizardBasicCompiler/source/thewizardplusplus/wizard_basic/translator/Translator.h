#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "../parser/Parser.h"
#include "Program.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class Translator {
public:
	std::string translate(const thewizardplusplus::wizard_basic::parser::Parser
		::ParseTree& parse_tree);

private:
	boost::shared_ptr<Program> program;

	std::string getNodeValue(const wizard_basic::parser::Parser::ParseTree::
		const_iterator& parse_tree_node) const;
	void translateLine(const wizard_basic::parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
	void translateStatement(const wizard_basic::parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
	void translateStatementArrayDefinition(const wizard_basic::parser::Parser::
		ParseTree::const_iterator& parse_tree_node);
	void translateStatementAssign(const wizard_basic::parser::Parser::ParseTree
		::const_iterator& parse_tree_node);
	void translateStatementJump(const wizard_basic::parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
	std::string translateExpression(const wizard_basic::parser::Parser::
		ParseTree::const_iterator& parse_tree_node);
};

}
}
}
#endif
