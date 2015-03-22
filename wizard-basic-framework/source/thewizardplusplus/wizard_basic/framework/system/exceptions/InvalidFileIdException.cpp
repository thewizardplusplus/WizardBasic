#include "InvalidFileIdException.h"
#include "../../utils/Converter.h"

using namespace thewizardplusplus::wizard_basic_2::framework::system::exceptions;
using namespace thewizardplusplus::wizard_basic_2::framework::utils;

InvalidFileIdException::InvalidFileIdException(float file_id) :
	SystemException("invalid file ID " + Converter::toString(file_id))
{}
