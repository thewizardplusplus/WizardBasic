#include "SoundException.h"

using namespace thewizardplusplus::wizard_basic_2::framework::sound::exceptions;

SoundException::SoundException(const std::string& message) :
	WizardBasicFrameworkException("error in sound module - " + message)
{}
