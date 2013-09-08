#include "IncorrectTypesOfFunctionParameterException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost;

IncorrectTypesOfFunctionParameterException::
	IncorrectTypesOfFunctionParameterException(ValueType::Types expected_type,
	ValueType::Types received_type)
:
	IllegalFunctionCallOperationException(expected_type, received_type)
{}

void IncorrectTypesOfFunctionParameterException::setNumberOfParameter(
	size_t number)
{
	translate_message += (format("; with parameter number %1%") % number).
		str();
}
