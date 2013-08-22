#include "WizardBasicFrameworkException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::framework;
using namespace thewizardplusplus::wizard_basic::framework::exceptions;
using namespace boost;

WizardBasicFrameworkException::WizardBasicFrameworkException(const std::string&
	message)
:
	std::runtime_error((format("Wizard BASIC: %1%.") % message).str())
{}
