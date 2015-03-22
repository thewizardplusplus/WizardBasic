#include "NumberVariable.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic_2::compiler::translator;
using namespace boost;

NumberVariable::NumberVariable(const std::string& name) :
	Variable(name)
{}

std::string NumberVariable::getCppDefinition(void) const {
	return (format("\tfloat %1%;\n") % name).str();
}
