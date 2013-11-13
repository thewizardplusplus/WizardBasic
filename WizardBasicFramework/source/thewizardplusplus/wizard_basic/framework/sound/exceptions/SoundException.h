#ifndef SOUNDEXCEPTION_H
#define SOUNDEXCEPTION_H

#include "../../exceptions/WizardBasicFrameworkException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace sound {
namespace exceptions {

class SoundException : public framework::exceptions::
	WizardBasicFrameworkException
{
public:
	SoundException(const std::string& message);
};

}
}
}
}
}
#endif
