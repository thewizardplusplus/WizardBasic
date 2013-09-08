#include "StringVariable.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace boost;

StringVariable::StringVariable(const std::string& name, const std::string&
	string)
:
	ArrayVariable(name, string.length()),
	string(string)
{}

std::string StringVariable::getCppDefinition(void) const {
	return (format("\tSTRING(%1%, \"%2%\");\n") % name % string).str();
}
