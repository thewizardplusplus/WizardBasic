#ifndef WIZARDBASICGRAMMARRULE_H
#define WIZARDBASICGRAMMARRULE_H

#include <boost/spirit/home/classic/core.hpp>
#include <map>

namespace thewizardplusplus {
namespace wizard_basic {
namespace parser {

class WizardBasicGrammarRule {
public:
	enum Types {
		ROOT,
		PROGRAM,
		LINE,

		STATEMENT,
		STATEMENT_ARRAY_DEFINITION,
		STATEMENT_ASSIGN,
		STATEMENT_JUMP,
		STATEMENT_CONDITION,

		EXPRESSION_ADDITION,
		EXPRESSION_MULTIPLICATION,
		EXPRESSION_ATOM,

		COMMENT,
		IDENTIFIER,
		ARRAY_ACCESS,
		FUNCTION_CALL,

		LINE_BREAK,
		CONSTANT_POSITIVE_INTEGER,
		CONSTANT_REAL,
		CONSTANT_STRING
	};

	static const std::map<boost::spirit::classic::parser_id, std::string> NAMES;
};

}
}
}
#endif
