#ifndef REALMATCHER_H
#define REALMATCHER_H

#include <boost/spirit/home/classic/core.hpp>

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace parser {

class UnsignedRealParserPolicies : public boost::spirit::classic::
	ureal_parser_policies<float>
{
public:
	static const bool allow_leading_dot =  false;
	static const bool allow_trailing_dot = false;

	template<typename ScannerType>
	static typename boost::spirit::classic::parser_result<uint_parser_t,
		ScannerType>::type parse_n(ScannerType& scan);
	template<typename ScannerType>
	static typename boost::spirit::classic::parser_result<boost::spirit::classic
		::chlit<>, ScannerType>::type parse_exp(ScannerType& scan);
	template<typename ScannerType>
	static typename boost::spirit::classic::parser_result<int_parser_t,
		ScannerType>::type parse_exp_n(ScannerType& scan);
};

template<typename ScannerType>
typename boost::spirit::classic::parser_result<UnsignedRealParserPolicies::
	uint_parser_t, ScannerType>::type UnsignedRealParserPolicies::parse_n(
	ScannerType& scan)
{
	using namespace boost::spirit::classic;
	return (ch_p('0') ^ (uint_parser<float, 10, 1, 1>() - '0') >> !uint_p).
		parse(scan);
}

template<typename ScannerType>
typename boost::spirit::classic::parser_result<boost::spirit::classic::chlit<>,
	ScannerType>::type UnsignedRealParserPolicies::parse_exp(ScannerType& scan)
{
	(void)scan;
	return scan.no_match();
}

template<typename ScannerType>
typename boost::spirit::classic::parser_result<UnsignedRealParserPolicies::
	int_parser_t, ScannerType>::type UnsignedRealParserPolicies::parse_exp_n(
	ScannerType& scan)
{
	(void)scan;
	return scan.no_match();
}

}
}
}
}
#endif
