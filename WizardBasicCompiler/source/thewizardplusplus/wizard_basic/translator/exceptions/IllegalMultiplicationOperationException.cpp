#include "IllegalMultiplicationOperationException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

IllegalMultiplicationOperationException::
	IllegalMultiplicationOperationException(MultiplicationType::Types
	multiplication_type, ValueType::Types operand1_type, ValueType::Types
	operand2_type)
:
	IllegalOperationException((format("multiplication operation \"%1%\"") %
		MultiplicationType::convertToCppCode(multiplication_type)).str(),
		operand1_type, operand2_type)
{}
