#include "InvalidOpenFileModeException.h"
#include "../../utils/Converter.h"

using namespace thewizardplusplus::wizard_basic::framework::system::exceptions;
using namespace thewizardplusplus::wizard_basic::framework::utils;

InvalidOpenFileModeException::InvalidOpenFileModeException(float mode) :
	SystemException("invalid open file mode " + Converter::toString(mode) +
		"; expected 0, 1, or 2")
{}
