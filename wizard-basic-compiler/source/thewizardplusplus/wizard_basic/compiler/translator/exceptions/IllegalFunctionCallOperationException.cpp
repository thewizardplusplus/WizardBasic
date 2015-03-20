#include "IllegalFunctionCallOperationException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost;

IllegalFunctionCallOperationException::IllegalFunctionCallOperationException(
	const std::string& message)
:
	IllegalOperationException("function call operation", message)
{}

IllegalFunctionCallOperationException::IllegalFunctionCallOperationException(
	ValueType::Types expected_type, ValueType::Types received_type)
:
	IllegalOperationException("function call operation", expected_type,
		received_type)
{}

void IllegalFunctionCallOperationException::setFunctionName(const std::string&
	name)
{
	translate_message += (format("; with function \"%1%()\"") % name).str();
}
