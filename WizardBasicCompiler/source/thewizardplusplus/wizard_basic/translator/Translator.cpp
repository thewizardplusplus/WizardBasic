#include "Translator.h"
#include "../utils/assert.h"
#include "../parser/WizardBasicGrammarRule.h"
#include "exceptions/TranslateException.h"
#include "ArrayVariable.h"
#include "StringVariable.h"
#include "AdditionExpression.h"
#include "MultiplicationExpression.h"
#include "RealConstantExpression.h"
#include "exceptions/UndefinedIdentifierException.h"
#include "IdentifierExpression.h"
#include "ArrayAccessExpression.h"
#include "FunctionCallExpression.h"
#include <boost/lexical_cast.hpp>
#include <typeinfo>

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
			program->addFunctionCallAsSatetement(translateFunctionCall(
				parse_tree_node));
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
			shared_ptr<Expression> expression = translateExpression(++child);
			program->addAssign(identifier, expression);
			break;
		}
		case WizardBasicGrammarRule::ARRAY_ACCESS: {
			shared_ptr<Expression> array_access = translateArrayAccess(child);
			shared_ptr<Expression> expression = translateExpression(++child);
			program->addAssign(array_access, expression);
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
	shared_ptr<Expression> left_expression = translateExpression(child++);
	shared_ptr<Expression> right_expression = translateExpression(child++);
	size_t label = lexical_cast<size_t>(getNodeValue(child));
	program->addCondition(ConditionType::convertFromWizardBasicCode(
		type_of_condition), left_expression, right_expression, label);
}

shared_ptr<Expression> Translator::translateExpression(const Parser::ParseTree::
	const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::
		EXPRESSION_ADDITION || parse_tree_node->value.id() ==
		WizardBasicGrammarRule::EXPRESSION_MULTIPLICATION || parse_tree_node->
		value.id() == WizardBasicGrammarRule::CONSTANT_REAL || parse_tree_node->
		value.id() == WizardBasicGrammarRule::IDENTIFIER || parse_tree_node->
		value.id() == WizardBasicGrammarRule::ARRAY_ACCESS || parse_tree_node->
		value.id() == WizardBasicGrammarRule::FUNCTION_CALL, "Wizard BASIC: "
		"translating error - unknown statement; expected EXPRESSION_ADDITION, "
		"EXPRESSION_MULTIPLICATION, CONSTANT_REAL, IDENTIFIER, ARRAY_ACCESS or "
		"FUNCTION_CALL.");

	switch (parse_tree_node->value.id().to_long()) {
		case WizardBasicGrammarRule::EXPRESSION_ADDITION:
			return translateExpressionAddition(parse_tree_node);
		case WizardBasicGrammarRule::EXPRESSION_MULTIPLICATION:
			return translateExpressionMultiplication(parse_tree_node);
		case WizardBasicGrammarRule::CONSTANT_REAL:
			return translateConstantReal(parse_tree_node);
		case WizardBasicGrammarRule::IDENTIFIER:
			return translateIdentifier(parse_tree_node);
		case WizardBasicGrammarRule::ARRAY_ACCESS:
			return translateArrayAccess(parse_tree_node);
		case WizardBasicGrammarRule::FUNCTION_CALL:
			return translateFunctionCall(parse_tree_node);
	}

	// dummy for warning
	return shared_ptr<Expression>();
}

shared_ptr<Expression> Translator::translateExpressionAddition(const Parser::
	ParseTree::const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::
		EXPRESSION_ADDITION, "Wizard BASIC: translating error - invalid node; "
		"expected EXPRESSION_ADDITION.");
	ASSERT(parse_tree_node->children.size() == 2, "Wizard BASIC: translating "
		"error - invalid children number of node; expected 2.");

	std::string type_of_addition = getNodeValue(parse_tree_node);
	ASSERT(type_of_addition == "+" || type_of_addition == "-", "Wizard BASIC: "
		"translating error - invalid value of node; expected \"+\" or \"-\".");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	shared_ptr<Expression> operand1 = translateExpression(child);
	shared_ptr<Expression> operand2 = translateExpression(++child);

	return shared_ptr<Expression>(new AdditionExpression(operand1, AdditionType
		::convertFromWizardBasicCode(type_of_addition), operand2));
}

shared_ptr<Expression> Translator::translateExpressionMultiplication(const
	Parser::ParseTree::const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::
		EXPRESSION_MULTIPLICATION, "Wizard BASIC: translating error - invalid "
		"node; expected EXPRESSION_MULTIPLICATION.");
	ASSERT(parse_tree_node->children.size() == 2, "Wizard BASIC: translating "
		"error - invalid children number of node; expected 2.");

	std::string type_of_multiplication = getNodeValue(parse_tree_node);
	ASSERT(type_of_multiplication == "*" || type_of_multiplication == "/",
		"Wizard BASIC: translating error - invalid value of node; expected "
		"\"*\" or \"/\".");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	shared_ptr<Expression> operand1 = translateExpression(child);
	shared_ptr<Expression> operand2 = translateExpression(++child);

	return shared_ptr<Expression>(new MultiplicationExpression(operand1,
		MultiplicationType::convertFromWizardBasicCode(type_of_multiplication),
		operand2));
}

shared_ptr<Expression> Translator::translateConstantReal(const Parser::ParseTree
	::const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::CONSTANT_REAL,
		"Wizard BASIC: translating error - invalid node; expected "
		"CONSTANT_REAL.");

	return shared_ptr<Expression>(new RealConstantExpression(lexical_cast<
		float>(getNodeValue(parse_tree_node))));
}

shared_ptr<Expression> Translator::translateIdentifier(const Parser::ParseTree::
	const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::IDENTIFIER,
		"Wizard BASIC: translating error - invalid node; expected IDENTIFIER.");

	std::string identifier = getNodeValue(parse_tree_node);
	shared_ptr<Variable> variable = program->getVariables().getVariableByName(
		identifier);
	if (!variable) {
		throw UndefinedIdentifierException(identifier);
	}

	return shared_ptr<Expression>(new IdentifierExpression(variable));
}

shared_ptr<Expression> Translator::translateArrayAccess(const Parser::ParseTree
	::const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::ARRAY_ACCESS,
		"Wizard BASIC: translating error - invalid node; expected "
		"ARRAY_ACCESS.");
	ASSERT(parse_tree_node->children.size() == 2, "Wizard BASIC: translating "
		"error - invalid children number of node; expected 2.");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	ASSERT(child->value.id() == WizardBasicGrammarRule::IDENTIFIER, "Wizard "
		"BASIC: translating error - invalid node; expected IDENTIFIER.");

	std::string identifier = getNodeValue(child++);
	shared_ptr<Variable> variable = program->getVariables().getVariableByName(
		identifier);
	if (!variable) {
		throw UndefinedIdentifierException(identifier);
	}

	shared_ptr<Expression> index = translateExpression(child);
	std::string index_variable_name = program->addTestArrayBounds(variable,
		index);

	return shared_ptr<Expression>(new ArrayAccessExpression(variable, index,
		index_variable_name));
}

shared_ptr<Expression> Translator::translateFunctionCall(const Parser::ParseTree
	::const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::FUNCTION_CALL,
		"Wizard BASIC: translating error - invalid node; expected "
		"FUNCTION_CALL.");

	return shared_ptr<Expression>(new FunctionCallExpression());
}
