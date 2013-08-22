#ifndef ILLEGALMULTIPLICATIONOPERATIONEXCEPTION_H
#define ILLEGALMULTIPLICATIONOPERATIONEXCEPTION_H

#include "IllegalOperationException.h"
#include "../MultiplicationType.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {
namespace exceptions {

class IllegalMultiplicationOperationException : public IllegalOperationException
{
public:
	IllegalMultiplicationOperationException(MultiplicationType::Types
		multiplication_type, ValueType::Types operand1_type, ValueType::Types
		operand2_type);
};

}
}
}
}
}
#endif
