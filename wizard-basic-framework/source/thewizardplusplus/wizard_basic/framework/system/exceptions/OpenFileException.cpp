#include "OpenFileException.h"

using namespace thewizardplusplus::wizard_basic::framework::system::exceptions;

OpenFileException::OpenFileException(const std::string& filename) :
	SystemException("unable to open file \"" + filename + "\"")
{}
