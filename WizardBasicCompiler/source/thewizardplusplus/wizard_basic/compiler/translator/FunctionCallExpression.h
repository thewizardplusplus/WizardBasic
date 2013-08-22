#ifndef FUNCTIONCALLEXPRESSION_H
#define FUNCTIONCALLEXPRESSION_H

#include "Expression.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class FunctionCallExpression : public Expression {
public:
	FunctionCallExpression(void);
	virtual std::string getCppCode(void) const;
};

}
}
}
}
#endif
