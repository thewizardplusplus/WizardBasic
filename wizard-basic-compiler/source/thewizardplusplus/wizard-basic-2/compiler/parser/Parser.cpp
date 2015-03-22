#include "Parser.h"
#include "WizardBasicGrammar.h"
#include "exceptions/ParsingException.h"
#include "exceptions/CodePosition.h"

using namespace thewizardplusplus::wizard_basic_2::compiler::parser;
using namespace thewizardplusplus::wizard_basic_2::compiler::parser::exceptions;
using namespace boost::spirit::classic;

Parser::ParseTree Parser::parse(const std::string& code) {
	tree_parse_info<std::string::const_iterator, node_iter_data_factory<> >
		parse_tree_info = ast_parse<node_iter_data_factory<> >(code.begin(),
		code.end(), WizardBasicGrammar(), space_p - eol_p);
	if (!parse_tree_info.full) {
		throw ParsingException(CodePosition(code.substr(0, std::distance(code.
			begin(), parse_tree_info.stop))));
	}

	return parse_tree_info.trees;
}
