#ifndef PARSER_H
#define PARSER_H

#include <boost/spirit/home/classic/tree/common.hpp>

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace parser {

class Parser {
public:
	typedef boost::spirit::classic::tree_match<std::string::const_iterator,
		boost::spirit::classic::node_iter_data_factory<> >::container_t
		ParseTree;

	ParseTree parse(const std::string& code);
};

}
}
}
}
#endif
