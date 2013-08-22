#ifndef DUPLICATEVARIABLESEXCEPTION_H
#define DUPLICATEVARIABLESEXCEPTION_H

#include "TranslateException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {
namespace exceptions {

class DuplicateVariablesException : public TranslateException {
public:
	DuplicateVariablesException(const std::string& variable_name);
};

}
}
}
}
}
#endif
