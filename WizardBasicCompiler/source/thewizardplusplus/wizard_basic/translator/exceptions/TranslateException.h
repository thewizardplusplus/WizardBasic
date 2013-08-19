#ifndef TRANSLATEEXCEPTION_H
#define TRANSLATEEXCEPTION_H

#include "../../exceptions/WizardBasicException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {
namespace exceptions {

class TranslateException : public wizard_basic::exceptions::WizardBasicException
{
public:
	TranslateException(const std::string& message);
	virtual ~TranslateException(void) throw();
	void setLineLabel(size_t line_label);

private:
	std::string translate_message;
};

}
}
}
}
#endif
