#include "SystemException.h"

using namespace thewizardplusplus::wizard_basic::framework::system::exceptions;

SystemException::SystemException(const std::string& message) :
	WizardBasicFrameworkException("error in system module - " + message)
{}
