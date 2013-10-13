#ifndef INVALIDOPENDFILEMODEEXCEPTION_H
#define INVALIDOPENDFILEMODEEXCEPTION_H

#include "SystemException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace system {
namespace exceptions {

class InvalidOpenFileModeException : public SystemException {
public:
	InvalidOpenFileModeException(float mode);
};

}
}
}
}
}
#endif
