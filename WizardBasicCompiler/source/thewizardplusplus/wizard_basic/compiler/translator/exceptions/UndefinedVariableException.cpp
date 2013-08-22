#include "UndefinedVariableException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost;

UndefinedVariableException::UndefinedVariableException(const std::string&
	variable_name)
:
	TranslateException((format("undefined variable \"%1%\"") % variable_name).
		str())
{}
