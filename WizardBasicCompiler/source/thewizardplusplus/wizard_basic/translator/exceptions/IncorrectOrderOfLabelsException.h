#ifndef INCORRECTORDEROFLABELSEXCEPTION_H
#define INCORRECTORDEROFLABELSEXCEPTION_H

#include "../../exceptions/WizardBasicException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {
namespace exceptions {

class IncorrectOrderOfLabelsException : public thewizardplusplus::wizard_basic::
	exceptions::WizardBasicException
{
public:
	IncorrectOrderOfLabelsException(size_t label);

private:
	static const std::string MESSAGE;
};

}
}
}
}
#endif
