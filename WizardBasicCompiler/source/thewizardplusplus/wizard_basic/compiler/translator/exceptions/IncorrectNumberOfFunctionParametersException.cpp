#include "IncorrectNumberOfFunctionParametersException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost;

IncorrectNumberOfFunctionParametersException::
	IncorrectNumberOfFunctionParametersException(size_t expected_number, size_t
	received_number)
:
	IllegalFunctionCallOperationException((format("incorrect number of function"
		" parameters; received %1%, but expected %2%") % received_number %
		expected_number).str())
{}
