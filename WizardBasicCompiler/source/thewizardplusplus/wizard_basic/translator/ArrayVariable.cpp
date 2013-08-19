#include "ArrayVariable.h"
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace boost;

ArrayVariable::ArrayVariable(const std::string& name, size_t size) :
	Variable(name),
	size(size)
{}

size_t ArrayVariable::getSize(void) const {
	return size;
}

std::string ArrayVariable::getCppDefinition(void) const {
	return (format("\tfloat %1%[%2%_SIZE] = {0.0f};\n") % name % to_upper_copy(
		name)).str();
}
