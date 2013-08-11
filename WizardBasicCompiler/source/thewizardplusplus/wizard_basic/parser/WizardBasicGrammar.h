#ifndef WIZARDBASICGRAMMAR_H
#define WIZARDBASICGRAMMAR_H

#include "WizardBasicGrammarRule.h"
#include "UnsignedRealParserPolicies.h"
#include <boost/spirit/home/classic/tree/parse_tree.hpp>
#include <boost/spirit/home/classic/tree/ast.hpp>
#include <boost/spirit/home/classic/utility.hpp>

namespace thewizardplusplus {
namespace wizard_basic {
namespace parser {

class WizardBasicGrammar : public boost::spirit::classic::grammar<
	WizardBasicGrammar>
{
public:
	template <typename ScannerType>
	class definition {
	public:
		inline definition(const WizardBasicGrammar& wizard_basic_grammar);
		inline const boost::spirit::classic::rule<ScannerType, boost::spirit::
			classic::parser_tag<static_cast<int>(WizardBasicGrammarRule::
			ROOT)> >& start(void) const;

	private:
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::ROOT)> > root;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::PROGRAM)> >
			program;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::LINE)> > line;

		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::STATEMENT)> >
			statement;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::
			STATEMENT_ARRAY_DEFINITION)> > statement_array_definition;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::
			STATEMENT_ASSIGN)> > statement_assign;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::
			STATEMENT_JUMP)> > statement_jump;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::
			STATEMENT_CONDITION)> > statement_condition;

		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::
			EXPRESSION_ADDITION)> > expression_addition;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::
			EXPRESSION_MULTIPLICATION)> > expression_multiplication;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::
			EXPRESSION_ATOM)> > expression_atom;

		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::COMMENT)> >
			comment;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::IDENTIFIER)> >
			identifier;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::ARRAY_ACCESS)> >
			array_access;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::
			FUNCTION_CALL)> > function_call;

		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::LINE_BREAK)> >
			line_break;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::
			CONSTANT_POSITIVE_INTEGER)> > constant_positive_integer;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::
			CONSTANT_REAL)> > constant_real;
		boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
			parser_tag<static_cast<int>(WizardBasicGrammarRule::
			CONSTANT_STRING)> > constant_string;
	};
};

template <typename ScannerType>
WizardBasicGrammar::definition<ScannerType>::definition(const
	WizardBasicGrammar& wizard_basic_grammar)
{
	(void)wizard_basic_grammar;
	using namespace boost::spirit::classic;

	root = gen_pt_node_d[program];
	program = infix_node_d[gen_pt_node_d[line] % line_break] >> !discard_node_d[
		line_break];
	line = constant_positive_integer >> !(statement ^ discard_node_d[comment]);

	statement = statement_array_definition ^ statement_assign ^ gen_pt_node_d[
		statement_jump] ^ statement_condition ^ gen_pt_node_d[function_call];
	statement_array_definition = discard_node_d[str_p("DIM")] >> identifier >>
		(inner_node_d[ch_p('[') >> constant_positive_integer >> ']'] ^
		discard_node_d[ch_p('=')] >> constant_string);
	statement_assign = discard_node_d[str_p("LET")] >> longest_d[identifier |
		array_access] >> discard_node_d[ch_p('=')] >> expression_addition;
	statement_jump = discard_node_d[str_p("GOTO")] >> lexeme_d[
		constant_positive_integer];
	statement_condition = discard_node_d[str_p("IF")] >> expression_addition >>
		root_node_d[ch_p('=') ^ '<' ^ '>'] >> expression_addition >>
		discard_node_d[str_p("THEN")] >> lexeme_d[constant_positive_integer];

	expression_addition = expression_multiplication % root_node_d[ch_p('+') ^
		'-'];
	expression_multiplication = expression_atom % root_node_d[ch_p('*') ^ '/'];
	expression_atom = longest_d[constant_real | identifier | array_access |
		gen_pt_node_d[function_call] | inner_node_d['(' >> expression_addition
		>> ')']];

	comment = discard_node_d[str_p("REM")] >> !lexeme_d[token_node_d[*(anychar_p
		- line_break)]];
	identifier = lexeme_d[token_node_d[(alpha_p ^ '_') >> *(alnum_p ^ '_')]] -
		"DIM" - "LET" - "GOTO" - "IF" - "THEN" - "REM";
	array_access = identifier >> inner_node_d[ch_p('[') >> expression_addition
		>> ']'];
	function_call = identifier >> inner_node_d[ch_p('(') >> !infix_node_d[
		expression_addition % ','] >> ')'];

	line_break = eol_p;
	constant_positive_integer = token_node_d[(uint_parser<unsigned int, 10, 1,
		1>() - '0') >> !uint_p];
	constant_real = real_parser<float, UnsignedRealParserPolicies>();
	constant_string = lexeme_d[discard_node_d[ch_p('"')] >> token_node_d[
		*(c_escape_ch_p - '"')] >> discard_node_d[ch_p('"')]];
}

template <typename ScannerType>
const boost::spirit::classic::rule<ScannerType, boost::spirit::classic::
	parser_tag<static_cast<int>(WizardBasicGrammarRule::ROOT)> >&
	WizardBasicGrammar::definition<ScannerType>::start(void) const
{
	return root;
}

}
}
}
#endif
