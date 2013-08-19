#include "StringVariable.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace boost;

StringVariable::StringVariable(const std::string& name, const std::string&
	string)
:
	ArrayVariable(name, string.length()),
	string(string)
{}

std::string StringVariable::getString(void) const {
	return string;
}

std::string StringVariable::getCppDefinition(void) const {
	std::string symbol_codes;
	for (size_t i = 0; i < string.length(); i++) {
		if (i != 0) {
			symbol_codes += ", ";
		}
		symbol_codes += (format("%1%f") % static_cast<float>(string[i])).str();
	}

	return (format("\tfloat %1%[] = {%2%};\n") % name % symbol_codes).str();
}
