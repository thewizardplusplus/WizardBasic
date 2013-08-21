#include "IndexVariable.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace boost;

size_t IndexVariable::id = 0;

IndexVariable::IndexVariable(void) :
	Variable((format("index%1%") % ++id).str())
{}

std::string IndexVariable::getCppDefinition(void) const {
	return (format("\tsize_t %1%;\n") % name).str();
}
