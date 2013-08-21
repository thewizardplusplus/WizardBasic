#include "UndefinedIdentifierException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

UndefinedIdentifierException::UndefinedIdentifierException(const std::string&
	identifier)
:
	TranslateException((format("undefined identifier \"%1%\"") % identifier).
		str())
{}
