#include "UnknownFunctionException.h"

using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;

UnknownFunctionException::UnknownFunctionException(void) :
	IllegalFunctionCallOperationException("unknown function")
{}
