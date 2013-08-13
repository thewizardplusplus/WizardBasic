#ifndef DUPLICATELABELSEXCEPTION_H
#define DUPLICATELABELSEXCEPTION_H

#include "../../exceptions/WizardBasicException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {
namespace exceptions {

class DuplicateLabelsException : public thewizardplusplus::wizard_basic::
	exceptions::WizardBasicException
{
public:
	DuplicateLabelsException(size_t label);

private:
	static const std::string MESSAGE;
};

}
}
}
}
#endif
