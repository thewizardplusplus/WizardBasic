#include "WizardBasicException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic;
using namespace thewizardplusplus::wizard_basic::exceptions;
using namespace boost;

const std::string WizardBasicException::MESSAGE = "Wizard BASIC: %1%.";

WizardBasicException::WizardBasicException(const std::string& message) :
	std::runtime_error((format(MESSAGE) % message).str())
{}
