#include "WizardBasicCompilerException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic_2::compiler;
using namespace thewizardplusplus::wizard_basic_2::compiler::exceptions;
using namespace boost;

WizardBasicCompilerException::WizardBasicCompilerException(const std::string&
	message)
:
	std::runtime_error("Wizard BASIC 2: unknown error."),
	message(message)
{}

WizardBasicCompilerException::~WizardBasicCompilerException(void) throw() {}

const char* WizardBasicCompilerException::what(void) const throw() {
	return (format("Wizard BASIC 2: %1%.") % message).str().c_str();
}
