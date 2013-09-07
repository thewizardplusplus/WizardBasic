#include "UnknownFunctionException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost;

UnknownFunctionException::UnknownFunctionException(const std::string& name) :
	IllegalFunctionCallOperationException((format("unknown function \"%1%\"") %
		name).str())
{}
