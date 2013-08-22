#include "BaseException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::framework::base::exceptions;
using namespace boost;

BaseException::BaseException(const std::string& message) :
	WizardBasicFrameworkException((format("error in base module - %1%") %
		message).str())
{}
