#include "GraphicsException.h"

using namespace thewizardplusplus::wizard_basic::framework::graphics::
	exceptions;

GraphicsException::GraphicsException(const std::string& message) :
	WizardBasicFrameworkException("error in graphics module - " + message)
{}
