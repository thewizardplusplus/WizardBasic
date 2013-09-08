#include "ArrayVariable.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace boost;

ArrayVariable::ArrayVariable(const std::string& name, size_t size) :
	Variable(name),
	size(size)
{}

std::string ArrayVariable::getCppDefinition(void) const {
	return (format("\tARRAY(%1%, %2%);\n") % name % size).str();
}
