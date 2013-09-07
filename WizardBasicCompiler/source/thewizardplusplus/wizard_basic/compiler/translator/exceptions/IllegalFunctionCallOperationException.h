#ifndef ILLEGALFUNCTIONCALLOPERATIONEXCEPTION_H
#define ILLEGALFUNCTIONCALLOPERATIONEXCEPTION_H

#include "IllegalOperationException.h"
#include "../ValueType.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {
namespace exceptions {

class IllegalFunctionCallOperationException : public IllegalOperationException {
public:
	IllegalFunctionCallOperationException(const std::string& message);
	IllegalFunctionCallOperationException(ValueType::Types expected_type,
		ValueType::Types received_type);
};

}
}
}
}
}
#endif
