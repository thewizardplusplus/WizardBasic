#include "IllegalArrayAccessOperationException.h"

using namespace thewizardplusplus::wizard_basic::translator::exceptions;

IllegalArrayAccessOperationException::IllegalArrayAccessOperationException(
	ValueType::Types operand1_type, ValueType::Types operand2_type)
:
	IllegalOperationException("array access operation", operand1_type,
		operand2_type)
{}
