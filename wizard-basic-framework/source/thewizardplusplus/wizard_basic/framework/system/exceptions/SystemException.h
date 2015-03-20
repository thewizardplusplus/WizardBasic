#ifndef SYSTEMEXCEPTION_H
#define SYSTEMEXCEPTION_H

#include "../../exceptions/WizardBasicFrameworkException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace system {
namespace exceptions {

class SystemException : public framework::exceptions::
	WizardBasicFrameworkException
{
public:
	SystemException(const std::string& message);
};

}
}
}
}
}
#endif
