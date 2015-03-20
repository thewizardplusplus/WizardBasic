#include "CompilerException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::compiler::exceptions;
using namespace thewizardplusplus::wizard_basic::compiler::exceptions;
using namespace boost;

CompilerException::CompilerException(const std::string& message) :
	WizardBasicCompilerException((format("compilling error - %1%") % message).
		str())
{}

//CompilerException::~CompilerException(void) throw() {}
