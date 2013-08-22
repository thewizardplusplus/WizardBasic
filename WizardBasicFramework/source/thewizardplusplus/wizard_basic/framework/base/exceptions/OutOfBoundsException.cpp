#include "OutOfBoundsException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::framework::base::exceptions;
using namespace boost;

OutOfBoundsException::OutOfBoundsException(const std::string& array_name, size_t
	array_size, float rounded_index)
:
	BaseException((format("out of bounds of array \"%1%\"; array size is %2%; "
		"rounded index is %3%") % array_name % array_size % rounded_index).
		str())
{}
