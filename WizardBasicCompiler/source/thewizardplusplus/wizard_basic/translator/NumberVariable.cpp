#include "NumberVariable.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace boost;

NumberVariable::NumberVariable(const std::string& name, float initial_value) :
	Variable(name),
	initial_value(initial_value)
{}

std::string NumberVariable::getCppDefinition(void) const {
	return (format("\tfloat %1% = %2%f;\n") % name % initial_value).str();
}
