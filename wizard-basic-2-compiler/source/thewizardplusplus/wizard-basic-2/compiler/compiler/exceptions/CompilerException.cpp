#include "CompilerException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic_2::compiler::compiler::exceptions;
using namespace thewizardplusplus::wizard_basic_2::compiler::exceptions;
using namespace boost;

CompilerException::CompilerException(const std::string& message) :
	WizardBasicCompilerException((format("compilling error - %1%") % message).
		str())
{}

//CompilerException::~CompilerException(void) throw() {}
