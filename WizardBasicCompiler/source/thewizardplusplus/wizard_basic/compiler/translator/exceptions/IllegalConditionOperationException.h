#ifndef ILLEGALCONDITIONOPERATIONEXCEPTION_H
#define ILLEGALCONDITIONOPERATIONEXCEPTION_H

#include "IllegalOperationException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {
namespace exceptions {

class IllegalConditionOperationException : public IllegalOperationException
{
public:
	IllegalConditionOperationException(ValueType::Types operand1_type, ValueType
		::Types operand2_type);
};

}
}
}
}
}
#endif
