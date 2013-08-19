#include "DuplicateVariablesException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

DuplicateVariablesException::DuplicateVariablesException(const std::string&
	variable_name)
:
	TranslateException((format("duplicate variable \"%1%\"") % variable_name).
		str())
{}
