#include "WizardBasicException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic;
using namespace thewizardplusplus::wizard_basic::exceptions;
using namespace boost;

WizardBasicException::WizardBasicException(const std::string& message) :
	std::runtime_error("Wizard BASIC: impossible error."),
	message(message)
{}

WizardBasicException::~WizardBasicException(void) throw() {}

const char* WizardBasicException::what(void) const throw() {
	return (format("Wizard BASIC: %1%.") % message).str().c_str();
}
