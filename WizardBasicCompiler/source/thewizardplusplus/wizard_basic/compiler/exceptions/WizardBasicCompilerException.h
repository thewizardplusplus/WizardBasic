#ifndef WIZARDBASICCOMPILEREXCEPTION_H
#define WIZARDBASICCOMPILEREXCEPTION_H

#include <stdexcept>

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace exceptions {

class WizardBasicCompilerException : public std::runtime_error {
public:
	WizardBasicCompilerException(const std::string& message);
	virtual ~WizardBasicCompilerException(void) throw();
	virtual const char* what(void) const throw();

protected:
	std::string message;
};

}
}
}
}
#endif
