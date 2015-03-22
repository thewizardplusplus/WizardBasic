#ifndef FUNCTIONCALLEXPRESSION_H
#define FUNCTIONCALLEXPRESSION_H

#include "Expression.h"
#include "Function.h"

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace translator {

class FunctionCallExpression : public Expression {
public:
	FunctionCallExpression(const Function& function);
	virtual std::string getCppCode(void) const;

private:
	Function function;
};

}
}
}
}
#endif
