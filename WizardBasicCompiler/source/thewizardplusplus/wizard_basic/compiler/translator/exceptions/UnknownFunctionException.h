#ifndef UNKNOWNFUNCTIONEXCEPTION_H
#define UNKNOWNFUNCTIONEXCEPTION_H

#include "IllegalFunctionCallOperationException.h"
#include "../ValueType.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {
namespace exceptions {

class UnknownFunctionException : public IllegalFunctionCallOperationException {
public:
	UnknownFunctionException(const std::string& name);
};

}
}
}
}
}
#endif
