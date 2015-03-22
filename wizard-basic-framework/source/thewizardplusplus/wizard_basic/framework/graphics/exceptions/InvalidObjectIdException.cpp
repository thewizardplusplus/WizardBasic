#include "InvalidObjectIdException.h"
#include "../../utils/Converter.h"

using namespace thewizardplusplus::wizard_basic_2::framework::graphics::
	exceptions;
using namespace thewizardplusplus::wizard_basic_2::framework::utils;

InvalidObjectIdException::InvalidObjectIdException(float object_id) :
	GraphicsException("invalid object ID " + Converter::toString(object_id))
{}
