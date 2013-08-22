#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "../parser/Parser.h"
#include "Program.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class Translator {
public:
	std::string translate(const parser::Parser::ParseTree& parse_tree);

private:
	boost::shared_ptr<Program> program;

	std::string getNodeValue(const parser::Parser::ParseTree::const_iterator&
		parse_tree_node) const;
	void translateLine(const parser::Parser::ParseTree::const_iterator&
		parse_tree_node);
	void translateStatement(const parser::Parser::ParseTree::const_iterator&
		parse_tree_node);
	void translateStatementArrayDefinition(const parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
	void translateStatementAssign(const parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
	void translateStatementJump(const parser::Parser::ParseTree::const_iterator&
		parse_tree_node);
	void translateStatementCondition(const parser::Parser::ParseTree::
		const_iterator&parse_tree_node);
	Expression::Pointer translateExpression(const parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
	Expression::Pointer translateExpressionAddition(const parser::Parser::
		ParseTree::const_iterator& parse_tree_node);
	Expression::Pointer translateExpressionMultiplication(const parser::Parser::
		ParseTree::const_iterator& parse_tree_node);
	Expression::Pointer translateConstantReal(const parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
	Expression::Pointer translateIdentifier(const parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
	Expression::Pointer translateArrayAccess(const parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
	Expression::Pointer translateFunctionCall(const parser::Parser::ParseTree::
		const_iterator& parse_tree_node);
};

}
}
}
}
#endif
