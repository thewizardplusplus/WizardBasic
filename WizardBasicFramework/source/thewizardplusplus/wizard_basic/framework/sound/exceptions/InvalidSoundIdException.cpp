#include "InvalidSoundIdException.h"
#include "../../utils/Converter.h"

using namespace thewizardplusplus::wizard_basic::framework::sound::exceptions;
using namespace thewizardplusplus::wizard_basic::framework::utils;

InvalidSoundIdException::InvalidSoundIdException(float sound_id) :
	SoundException("invalid sound ID " + Converter::toString(sound_id))
{}
