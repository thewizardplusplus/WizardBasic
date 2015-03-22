#ifndef REALCONSTANTEXPRESSION_H
#define REALCONSTANTEXPRESSION_H

#include "Expression.h"

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace translator {

class RealConstantExpression : public Expression {
public:
	RealConstantExpression(float real_constant);
	virtual std::string getCppCode(void) const;

private:
	float real_constant;
};

}
}
}
}
#endif
