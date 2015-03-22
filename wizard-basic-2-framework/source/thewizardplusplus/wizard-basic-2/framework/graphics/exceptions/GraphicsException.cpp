#include "GraphicsException.h"

using namespace thewizardplusplus::wizard_basic_2::framework::graphics::
	exceptions;

GraphicsException::GraphicsException(const std::string& message) :
	WizardBasicFrameworkException("error in graphics module - " + message)
{}
