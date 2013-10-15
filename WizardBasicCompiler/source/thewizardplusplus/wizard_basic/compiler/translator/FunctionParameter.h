#ifndef FUNCTIONPARAMETER_H
#define FUNCTIONPARAMETER_H

#include "ValueType.h"
#include "Expression.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class FunctionParameter {
public:
	FunctionParameter(ValueType::Types type);
	FunctionParameter(Expression::Pointer expression);
	ValueType::Types getType(void) const;
	std::string getCppCode(void) const;

private:
	ValueType::Types    type;
	Expression::Pointer expression;
};

}
}
}
}
#endif
