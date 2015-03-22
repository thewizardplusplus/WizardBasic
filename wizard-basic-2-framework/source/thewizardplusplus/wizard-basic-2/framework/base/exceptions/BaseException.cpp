#include "BaseException.h"

using namespace thewizardplusplus::wizard_basic_2::framework::base::exceptions;

BaseException::BaseException(const std::string& message) :
	WizardBasicFrameworkException("error in base module - " + message)
{}
