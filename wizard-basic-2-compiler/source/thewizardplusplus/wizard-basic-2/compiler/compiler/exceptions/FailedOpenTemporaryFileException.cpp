#include "FailedOpenTemporaryFileException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic_2::compiler::compiler::exceptions;
using namespace boost;

FailedOpenTemporaryFileException::FailedOpenTemporaryFileException(const std::
	string& filename)
:
	CompilerException((format("failed open temporary file \"%1%\"") % filename).
		str())
{}
