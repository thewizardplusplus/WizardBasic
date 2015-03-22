#include "WizardBasicFrameworkException.h"

using namespace thewizardplusplus::wizard_basic_2::framework;
using namespace thewizardplusplus::wizard_basic_2::framework::exceptions;

WizardBasicFrameworkException::WizardBasicFrameworkException(const std::string&
	message)
:
	std::runtime_error("Wizard BASIC 2: " + message + ".")
{}
