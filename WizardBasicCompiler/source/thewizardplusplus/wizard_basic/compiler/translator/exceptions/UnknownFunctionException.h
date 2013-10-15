#ifndef UNKNOWNFUNCTIONEXCEPTION_H
#define UNKNOWNFUNCTIONEXCEPTION_H

#include "IllegalFunctionCallOperationException.h"
#include "../FunctionList.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {
namespace exceptions {

class UnknownFunctionException : public IllegalFunctionCallOperationException {
public:
	UnknownFunctionException(const Function& searched_function, const
		FunctionList::SimpleFunctionList& finded_functions);

private:
	std::string prepareExceptionDescription(const Function& searched_function,
		const FunctionList::SimpleFunctionList& finded_functions) const;
};

}
}
}
}
}
#endif
