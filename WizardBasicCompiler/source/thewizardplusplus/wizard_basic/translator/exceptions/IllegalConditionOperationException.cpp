#include "IllegalConditionOperationException.h"

using namespace thewizardplusplus::wizard_basic::translator::exceptions;

IllegalConditionOperationException::IllegalConditionOperationException(ValueType
	::Types operand1_type, ValueType::Types operand2_type)
:
	IllegalOperationException("condition operation", operand1_type,
		operand2_type)
{}
