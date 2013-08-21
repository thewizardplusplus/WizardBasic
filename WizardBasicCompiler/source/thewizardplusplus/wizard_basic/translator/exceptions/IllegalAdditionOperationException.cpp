#include "IllegalAdditionOperationException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

IllegalAdditionOperationException::IllegalAdditionOperationException(
	AdditionType::Types addition_type, ValueType::Types operand1_type, ValueType
	::Types operand2_type)
:
	IllegalOperationException((format("addition operation \"%1%\"") %
		AdditionType::convertToCppCode(addition_type)).str(), operand1_type,
		operand2_type)
{}
