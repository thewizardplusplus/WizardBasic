#ifndef WIZARDBASICEXCEPTION_H
#define WIZARDBASICEXCEPTION_H

#include <stdexcept>

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace framework {
namespace exceptions {

class WizardBasicFrameworkException : public std::runtime_error {
public:
	WizardBasicFrameworkException(const std::string& message);
};

}
}
}
}
#endif
