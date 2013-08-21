#include "IllegalAssignOperationException.h"

using namespace thewizardplusplus::wizard_basic::translator::exceptions;

IllegalAssignOperationException::IllegalAssignOperationException(ValueType::
	Types operand1_type, ValueType::Types operand2_type)
:
	IllegalOperationException("assign operation", operand1_type, operand2_type)
{}
