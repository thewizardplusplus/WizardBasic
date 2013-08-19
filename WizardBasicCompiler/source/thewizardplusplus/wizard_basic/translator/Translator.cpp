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

std::string Translator::compile(const Parser::ParseTree& parse_tree) {
	program = shared_ptr<Program>(new Program());

	Parser::ParseTree::const_iterator parse_tree_node = parse_tree.begin();
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::PROGRAM,
		"Wizard BASIC: impossible translating error - invalid root node; "
		"expected PROGRAM.");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	Parser::ParseTree::const_iterator end = parse_tree_node->children.end();
	for (; child != end; ++child) {
		compileLine(child);
	}

	return program->getCppCode();
}

std::string Translator::getNodeValue(const Parser::ParseTree::const_iterator&
	parse_tree_node) const
{
	return std::string(parse_tree_node->value.begin(), parse_tree_node->value.
		end());
}

void Translator::compileLine(const Parser::ParseTree::const_iterator&
	parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::LINE, "Wizard"
		" BASIC: impossible translating error - invalid node; expected LINE.");
	ASSERT(parse_tree_node->children.size() == 1 || parse_tree_node-> children.
		size() == 2, "Wizard BASIC: impossible translating error - invalid "
		"children number of node; expected 1 or 2.");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	ASSERT(child->value.id() == WizardBasicGrammarRule::
		CONSTANT_POSITIVE_INTEGER, "Wizard BASIC: impossible translating error "
		"- invalid node; expected CONSTANT_POSITIVE_INTEGER.");
	size_t line_label = lexical_cast<size_t>(getNodeValue(child));

	try {
		program->addLabel(line_label);

		if (parse_tree_node->children.size() == 2) {
			compileStatement(++child);
		}
	} catch (TranslateException& exception) {
		exception.setLineLabel(line_label);
		throw;
	}
}

void Translator::compileStatement(const Parser::ParseTree::const_iterator&
	parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::
		STATEMENT_ARRAY_DEFINITION || parse_tree_node->value.id() ==
		WizardBasicGrammarRule::STATEMENT_ASSIGN || parse_tree_node->value.id()
		== WizardBasicGrammarRule::STATEMENT_JUMP || parse_tree_node->value.id()
		== WizardBasicGrammarRule::STATEMENT_CONDITION || parse_tree_node->value
		.id() == WizardBasicGrammarRule::FUNCTION_CALL, "Wizard BASIC: "
		"impossible translating error - unknown statement; expected "
		"STATEMENT_ARRAY_DEFINITION, STATEMENT_ASSIGN, STATEMENT_JUMP, "
		"STATEMENT_CONDITION or FUNCTION_CALL.");

	switch (parse_tree_node->value.id().to_long()) {
		case WizardBasicGrammarRule::STATEMENT_ARRAY_DEFINITION:
			compileStatementArrayDefinition(parse_tree_node);
			break;
		case WizardBasicGrammarRule::STATEMENT_ASSIGN:
			//compileStatementAssign(parse_tree_node);
			break;
		case WizardBasicGrammarRule::STATEMENT_JUMP:
			//compileStatementJump(parse_tree_node);
			break;
		case WizardBasicGrammarRule::STATEMENT_CONDITION:
			//compileStatementCondition(parse_tree_node);
			break;
		case WizardBasicGrammarRule::FUNCTION_CALL:
			//compileFunctionCall(parse_tree_node);
			break;
	}
}

void Translator::compileStatementArrayDefinition(const Parser::ParseTree::
	const_iterator& parse_tree_node)
{
	ASSERT(parse_tree_node->value.id() == WizardBasicGrammarRule::
		STATEMENT_ARRAY_DEFINITION, "Wizard BASIC: impossible translating error"
		" - invalid node; expected STATEMENT_ARRAY_DEFINITION.");
	ASSERT(parse_tree_node->children.size() == 2, "Wizard BASIC: impossible "
		"translating error - invalid children number of node; expected 2.");

	Parser::ParseTree::const_iterator child = parse_tree_node->children.begin();
	ASSERT(child->value.id() == WizardBasicGrammarRule::IDENTIFIER, "Wizard "
		"BASIC: impossible translating error - invalid node; expected "
		"IDENTIFIER.");
	std::string identifier = getNodeValue(child);

	child++;
	ASSERT(child->value.id() == WizardBasicGrammarRule::
		CONSTANT_POSITIVE_INTEGER || child->value.id() == WizardBasicGrammarRule
		::CONSTANT_STRING, "Wizard BASIC: impossible translating error - "
		"invalid node; expected CONSTANT_POSITIVE_INTEGER or CONSTANT_STRING.");
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
