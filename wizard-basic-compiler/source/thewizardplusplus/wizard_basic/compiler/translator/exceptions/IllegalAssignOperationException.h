#ifndef ILLEGALASSIGNOPERATIONEXCEPTION_H
#define ILLEGALASSIGNOPERATIONEXCEPTION_H

#include "IllegalOperationException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {
namespace exceptions {

class IllegalAssignOperationException : public IllegalOperationException
{
public:
	IllegalAssignOperationException(ValueType::Types operand1_type, ValueType::
		Types operand2_type);
};

}
}
}
}
}
#endif
