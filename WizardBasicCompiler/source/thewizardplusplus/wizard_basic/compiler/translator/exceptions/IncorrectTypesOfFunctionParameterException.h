#ifndef INCORRECTTYPESOFFUNCTIONPARAMETEREXCEPTION_H
#define INCORRECTTYPESOFFUNCTIONPARAMETEREXCEPTION_H

#include "IllegalFunctionCallOperationException.h"
#include "../ValueType.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {
namespace exceptions {

class IncorrectTypesOfFunctionParameterException : public
	IllegalFunctionCallOperationException
{
public:
	IncorrectTypesOfFunctionParameterException(ValueType::Types expected_type,
		ValueType::Types received_type);
	void setNumberOfParameter(size_t number);
};

}
}
}
}
}
#endif
