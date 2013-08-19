#ifndef WIZARDBASICEXCEPTION_H
#define WIZARDBASICEXCEPTION_H

#include <stdexcept>

namespace thewizardplusplus {
namespace wizard_basic {
namespace exceptions {

class WizardBasicException : public std::runtime_error {
public:
	WizardBasicException(const std::string& message);
	virtual ~WizardBasicException(void) throw();
	virtual const char* what(void) const throw();

protected:
	std::string message;
};

}
}
}
#endif
