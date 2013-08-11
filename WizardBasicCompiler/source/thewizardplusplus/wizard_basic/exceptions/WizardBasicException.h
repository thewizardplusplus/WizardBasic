#ifndef WIZARDBASICEXCEPTION_H
#define WIZARDBASICEXCEPTION_H

#include <stdexcept>

namespace thewizardplusplus {
namespace wizard_basic {
namespace exceptions {

class WizardBasicException : public std::runtime_error {
public:
	WizardBasicException(const std::string& message);

private:
	static const std::string MESSAGE;
};

}
}
}
#endif
