#include "OpenObjectFileException.h"

using namespace thewizardplusplus::wizard_basic::framework::graphics::
	exceptions;

OpenObjectFileException::OpenObjectFileException(const std::string&
	object_filename)
:
	GraphicsException("unable to open object file \"" + object_filename + "\"")
{}
