#include "WizardBasicCompilerException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler;
using namespace thewizardplusplus::wizard_basic::compiler::exceptions;
using namespace boost;

WizardBasicCompilerException::WizardBasicCompilerException(const std::string&
	message)
:
	std::runtime_error("Wizard BASIC: unknown error."),
	message(message)
{}

WizardBasicCompilerException::~WizardBasicCompilerException(void) throw() {}

const char* WizardBasicCompilerException::what(void) const throw() {
	return (format("Wizard BASIC: %1%.") % message).str().c_str();
}
