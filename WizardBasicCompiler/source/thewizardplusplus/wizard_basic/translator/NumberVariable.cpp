#include "NumberVariable.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace boost;

NumberVariable::NumberVariable(const std::string& name) :
	Variable(name),
	use_initial_value(false),
	initial_value(0.0f)
{}

NumberVariable::NumberVariable(const std::string& name, float initial_value) :
	Variable(name),
	use_initial_value(true),
	initial_value(initial_value)
{}

std::string NumberVariable::getCppDefinition(void) const {
	if (!use_initial_value) {
		return (format("\tfloat %1%;\n") % name).str();
	} else {
		return (format("\tfloat %1% = %2%f;\n") % name % initial_value).str();
	}
}
