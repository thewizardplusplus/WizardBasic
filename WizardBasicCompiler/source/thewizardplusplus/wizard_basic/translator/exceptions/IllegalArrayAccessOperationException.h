#ifndef ILLEGALARRAYACCESSOPERATIONEXCEPTION_H
#define ILLEGALARRAYACCESSOPERATIONEXCEPTION_H

#include "IllegalOperationException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {
namespace exceptions {

class IllegalArrayAccessOperationException : public IllegalOperationException {
public:
	IllegalArrayAccessOperationException(ValueType::Types operand1_type,
		ValueType::Types operand2_type);
};

}
}
}
}
#endif
