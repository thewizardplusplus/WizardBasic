#ifndef INVALIDSOUNDIDEXCEPTION_H
#define INVALIDSOUNDIDEXCEPTION_H

#include "SoundException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace sound {
namespace exceptions {

class InvalidSoundIdException : public SoundException {
public:
	InvalidSoundIdException(float sound_id);
};

}
}
}
}
}
#endif
