#ifndef TRANSLATEEXCEPTION_H
#define TRANSLATEEXCEPTION_H

#include "../../exceptions/WizardBasicCompilerException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {
namespace exceptions {

class TranslateException : public compiler::exceptions::
	WizardBasicCompilerException
{
public:
	TranslateException(const std::string& message);
	virtual ~TranslateException(void) throw();
	void setLineLabel(size_t line_label);

protected:
	std::string translate_message;
};

}
}
}
}
}
#endif
