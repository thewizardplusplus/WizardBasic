#include "OutOfBoundsException.h"
#include "../../utils/Converter.h"

using namespace thewizardplusplus::wizard_basic_2::framework::base::exceptions;
using namespace thewizardplusplus::wizard_basic_2::framework::utils;

OutOfBoundsException::OutOfBoundsException(const std::string& array_name, size_t
	array_size, float rounded_index)
:
	BaseException("out of bounds of array \"" + array_name + "\"; array size is"
		" " + Converter::toString(array_size) + "; rounded index is " +
		Converter::toString(rounded_index))
{}
