#ifndef ILLEGALADDITIONOPERATIONEXCEPTION_H
#define ILLEGALADDITIONOPERATIONEXCEPTION_H

#include "IllegalOperationException.h"
#include "../AdditionType.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {
namespace exceptions {

class IllegalAdditionOperationException : public IllegalOperationException {
public:
	IllegalAdditionOperationException(AdditionType::Types addition_type,
		ValueType::Types operand1_type, ValueType::Types operand2_type);
};

}
}
}
}
#endif
