#include "WizardBasicFrameworkException.h"

using namespace thewizardplusplus::wizard_basic::framework;
using namespace thewizardplusplus::wizard_basic::framework::exceptions;

WizardBasicFrameworkException::WizardBasicFrameworkException(const std::string&
	message)
:
	std::runtime_error("Wizard BASIC: " + message + ".")
{}
