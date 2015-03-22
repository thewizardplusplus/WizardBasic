#include "InvalidOpenFileModeException.h"
#include "../../utils/Converter.h"

using namespace thewizardplusplus::wizard_basic_2::framework::system::exceptions;
using namespace thewizardplusplus::wizard_basic_2::framework::utils;

InvalidOpenFileModeException::InvalidOpenFileModeException(float mode) :
	SystemException("invalid open file mode " + Converter::toString(mode) +
		"; expected 0, 1, or 2")
{}
