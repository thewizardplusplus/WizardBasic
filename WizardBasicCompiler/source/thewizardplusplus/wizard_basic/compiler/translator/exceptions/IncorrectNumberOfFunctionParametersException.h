#ifndef INCORRECTNUMBEROFFUNCTIONPARAMETEREXCEPTION_H
#define INCORRECTNUMBEROFFUNCTIONPARAMETEREXCEPTION_H

#include "IllegalFunctionCallOperationException.h"
#include "../ValueType.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {
namespace exceptions {

class IncorrectNumberOfFunctionParametersException : public
	IllegalFunctionCallOperationException
{
public:
	IncorrectNumberOfFunctionParametersException(size_t expected_number, size_t
		received_number);
};

}
}
}
}
}
#endif
