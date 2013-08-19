#include "Translator.h"
#include "../utils/assert.h"
#include "../parser/WizardBasicGrammarRule.h"
#include "exceptions/TranslateException.h"
#include "ArrayVariable.h"
#include "StringVariable.h"
#include <boost/lexical_cast.hpp>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace thewizardplusplus::wizard_basic::parser;
using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

std::string Translator::translate(const Parser::ParseTree& parse_tree) {
	program = shared_ptr<Program>(new Program());

	Parser::ParseTree::const_iterator parse_tree_node = parse_tree.begin();
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::PROGRAM,
		"Wizard BASIC: translating error - invalid root node; expected "
		"PROGRAM.");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	Parser::ParseTree::const_iterator end = parse_tree_node->children.end();
	for (; child != end; ++child) {
		translateLine(child);
	}

	return program->getCppCode();
}

std::string Translator::getNodeValue(const Parser::ParseTree::const_iterator&
	parse_tree_node) const
{
	return std::string(parse_tree_node->value.begin(), parse_tree_node->value.
		end());
}

void Translator::translateLine(const Parser::ParseTree::const_iterator&
	parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::LINE, "Wizard"
		" BASIC: translating error - invalid node; expected LINE.");
	ASSERT(parse_tree_node->children.size() == 1 || parse_tree_node-> children.
		size() == 2, "Wizard BASIC: translating error - invalid children number"
		" of node; expected 1 or 2.");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	ASSERT(child->value.id() == WizardBasicGrammarRule::
		CONSTANT_POSITIVE_INTEGER, "Wizard BASIC: translating error - invalid "
		"node; expected CONSTANT_POSITIVE_INTEGER.");
	size_t line_label = lexical_cast<size_t>(getNodeValue(child));

	try {
		program->addLabel(line_label);

		if (parse_tree_node->children.size() == 2) {
			translateStatement(++child);
		}
	} catch (TranslateException& exception) {
		exception.setLineLabel(line_label);
		throw;
	}
}

void Translator::translateStatement(const Parser::ParseTree::const_iterator&
	parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::
		STATEMENT_ARRAY_DEFINITION || parse_tree_node->value.id() ==
		WizardBasicGrammarRule::STATEMENT_ASSIGN || parse_tree_node->value.id()
		== WizardBasicGrammarRule::STATEMENT_JUMP || parse_tree_node->value.id()
		== WizardBasicGrammarRule::STATEMENT_CONDITION || parse_tree_node->value
		.id() == WizardBasicGrammarRule::FUNCTION_CALL, "Wizard BASIC: "
		"translating error - unknown statement; expected "
		"STATEMENT_ARRAY_DEFINITION, STATEMENT_ASSIGN, STATEMENT_JUMP, "
		"STATEMENT_CONDITION or FUNCTION_CALL.");

	switch (parse_tree_node->value.id().to_long()) {
		case WizardBasicGrammarRule::STATEMENT_ARRAY_DEFINITION:
			translateStatementArrayDefinition(parse_tree_node);
			break;
		case WizardBasicGrammarRule::STATEMENT_ASSIGN:
			translateStatementAssign(parse_tree_node);
			break;
		case WizardBasicGrammarRule::STATEMENT_JUMP:
			translateStatementJump(parse_tree_node);
			break;
		case WizardBasicGrammarRule::STATEMENT_CONDITION:
			translateStatementCondition(parse_tree_node);
			break;
		case WizardBasicGrammarRule::FUNCTION_CALL:
			//translateFunctionCall(parse_tree_node);
			break;
	}
}

void Translator::translateStatementArrayDefinition(const Parser::ParseTree::
	const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::
		STATEMENT_ARRAY_DEFINITION, "Wizard BASIC: translating error - invalid "
		"node; expected STATEMENT_ARRAY_DEFINITION.");
	ASSERT(parse_tree_node->children.size() == 2, "Wizard BASIC: translating "
		"error - invalid children number of node; expected 2.");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	ASSERT(child->value.id() == WizardBasicGrammarRule::IDENTIFIER, "Wizard "
		"BASIC: translating error - invalid node; expected IDENTIFIER.");
	std::string identifier = getNodeValue(child);

	++child;
	ASSERT(child->value.id() == WizardBasicGrammarRule::
		CONSTANT_POSITIVE_INTEGER || child->value.id() == WizardBasicGrammarRule
		::CONSTANT_STRING, "Wizard BASIC: translating error - invalid node; "
		"expected CONSTANT_POSITIVE_INTEGER or CONSTANT_STRING.");
	Variable* variable = NULL;
	switch (child->value.id().to_long()) {
		case WizardBasicGrammarRule::CONSTANT_POSITIVE_INTEGER:
			variable = new ArrayVariable(identifier, lexical_cast<size_t>(
				getNodeValue(child)));
			break;
		case WizardBasicGrammarRule::CONSTANT_STRING:
			variable = new StringVariable(identifier, getNodeValue(child));
			break;
	}
	if (variable != NULL) {
		program->addVariable(shared_ptr<Variable>(variable));
	}
}

void Translator::translateStatementAssign(const wizard_basic::parser::Parser::
	ParseTree::const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::
		STATEMENT_ASSIGN, "Wizard BASIC: translating error - invalid node; "
		"expected STATEMENT_ASSIGN.");
	ASSERT(parse_tree_node->children.size() == 2, "Wizard BASIC: translating "
		"error - invalid children number of node; expected 2.");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	ASSERT(child->value.id() == WizardBasicGrammarRule::IDENTIFIER || child->
		value.id() == WizardBasicGrammarRule::ARRAY_ACCESS, "Wizard BASIC: "
		"translating error - invalid node; expected IDENTIFIER or "
		"ARRAY_ACCESS.");
	switch (child->value.id().to_long()) {
		case WizardBasicGrammarRule::IDENTIFIER: {
			std::string identifier = getNodeValue(child);
			std::string expression = translateExpression(++child);
			program->addAssign(identifier, expression);
			break;
		}
		case WizardBasicGrammarRule::ARRAY_ACCESS: {
			ASSERT(child->children.size() == 2, "Wizard BASIC: translating "
				"error - invalid children number of node; expected 2.");
			Parser::ParseTree::const_iterator subchild = child->children.
				begin();
			ASSERT(subchild->value.id() == WizardBasicGrammarRule::IDENTIFIER,
				"Wizard BASIC: translating error - invalid node; expected "
				"IDENTIFIER.");
			std::string identifier = getNodeValue(subchild);
			std::string index_expression = translateExpression(++subchild);
			std::string expression = translateExpression(++child);
			program->addAssign(identifier, index_expression, expression);
			break;
		}
	}
}

void Translator::translateStatementJump(const wizard_basic::parser::Parser::
	ParseTree::const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::
		STATEMENT_JUMP, "Wizard BASIC: translating error - invalid node; "
		"expected STATEMENT_JUMP.");
	ASSERT(parse_tree_node->children.size() == 1, "Wizard BASIC: translating "
		"error - invalid children number of node; expected 1.");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	program->addJump(lexical_cast<size_t>(getNodeValue(child)));
}

void Translator::translateStatementCondition(const Parser::ParseTree::
	const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::
		STATEMENT_CONDITION, "Wizard BASIC: translating error - invalid node; "
		"expected STATEMENT_CONDITION.");
	ASSERT(parse_tree_node->children.size() == 3, "Wizard BASIC: translating "
		"error - invalid children number of node; expected 3.");
	std::string type_of_condition = getNodeValue(parse_tree_node);
	ASSERT(type_of_condition == "=" || type_of_condition == "<" ||
		type_of_condition == ">", "Wizard BASIC: translating error - invalid "
		"value of node; expected \"=\", \"<\" or \">\".");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	std::string left_expression = translateExpression(child++);
	std::string right_expression = translateExpression(child++);
	size_t label = lexical_cast<size_t>(getNodeValue(child));
	program->addCondition(ConditionType::convertFromWizardBasicCode(
		type_of_condition), left_expression, right_expression, label);
}

std::string Translator::translateExpression(const Parser::ParseTree::
	const_iterator& parse_tree_node)
{
	(void)parse_tree_node;
	return "<expression>";
}
