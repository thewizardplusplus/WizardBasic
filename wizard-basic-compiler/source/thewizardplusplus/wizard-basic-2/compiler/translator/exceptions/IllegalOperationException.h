#ifndef ILLEGALOPERATIONEXCEPTION_H
#define ILLEGALOPERATIONEXCEPTION_H

#include "TranslateException.h"
#include "../ValueType.h"

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace translator {
namespace exceptions {

class IllegalOperationException : public TranslateException {
public:
	IllegalOperationException(const std::string& operation_description,
		ValueType::Types operand1_type, ValueType::Types operand2_type);
	IllegalOperationException(const std::string& operation_description,
		const std::string& message);
};

}
}
}
}
}
#endif
