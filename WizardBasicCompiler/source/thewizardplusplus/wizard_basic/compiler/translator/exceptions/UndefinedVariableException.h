#ifndef UNDEFINEDVARIABLEEXCEPTION_H
#define UNDEFINEDVARIABLEEXCEPTION_H

#include "TranslateException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {
namespace exceptions {

class UndefinedVariableException : public TranslateException {
public:
	UndefinedVariableException(const std::string& variable_name);
};

}
}
}
}
}
#endif
