#include "InvalidSoundIdException.h"
#include "../../utils/Converter.h"

using namespace thewizardplusplus::wizard_basic_2::framework::sound::exceptions;
using namespace thewizardplusplus::wizard_basic_2::framework::utils;

InvalidSoundIdException::InvalidSoundIdException(float sound_id) :
	SoundException("invalid sound ID " + Converter::toString(sound_id))
{}
