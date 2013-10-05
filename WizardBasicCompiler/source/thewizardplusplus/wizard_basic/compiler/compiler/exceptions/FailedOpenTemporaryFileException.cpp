#include "FailedOpenTemporaryFileException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::compiler::exceptions;
using namespace boost;

FailedOpenTemporaryFileException::FailedOpenTemporaryFileException(const std::
	string& filename)
:
	CompilerException((format("failed open temporary file \"%1%\"") % filename).
		str())
{}
