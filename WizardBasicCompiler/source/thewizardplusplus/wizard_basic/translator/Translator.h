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
	void translateStatementCondition(const wizard_basic::parser::Parser::
		ParseTree::const_iterator&parse_tree_node);
	boost::shared_ptr<Expression> translateExpression(const wizard_basic::parser
		::Parser::ParseTree::const_iterator& parse_tree_node);
	boost::shared_ptr<Expression> translateExpressionAddition(const wizard_basic
		::parser::Parser::ParseTree::const_iterator& parse_tree_node);
	boost::shared_ptr<Expression> translateExpressionMultiplication(const
		wizard_basic::parser::Parser::ParseTree::const_iterator&
		parse_tree_node);
	boost::shared_ptr<Expression> translateConstantReal(const wizard_basic::
		parser::Parser::ParseTree::const_iterator& parse_tree_node);
	boost::shared_ptr<Expression> translateIdentifier(const wizard_basic::parser
		::Parser::ParseTree::const_iterator& parse_tree_node);
	boost::shared_ptr<Expression> translateArrayAccess(const wizard_basic::
		parser::Parser::ParseTree::const_iterator& parse_tree_node);
	boost::shared_ptr<Expression> translateFunctionCall(const wizard_basic::
		parser::Parser::ParseTree::const_iterator& parse_tree_node);
};

}
}
}
#endif
