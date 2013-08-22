#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include "../../exceptions/WizardBasicFrameworkException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace base {
namespace exceptions {

class BaseException : public framework::exceptions::
	WizardBasicFrameworkException
{
public:
	BaseException(const std::string& message);
};

}
}
}
}
}
#endif
