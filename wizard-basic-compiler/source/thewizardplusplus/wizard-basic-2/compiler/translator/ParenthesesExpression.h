#ifndef PARENTHESESEXPRESSION_H
#define PARENTHESESEXPRESSION_H

#include "Expression.h"
#include <boost/shared_ptr.hpp>

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace translator {

class ParenthesesExpression : public Expression {
public:
	ParenthesesExpression(const Expression::Pointer& operand);
	virtual std::string getCppCode(void) const;

private:
	Expression::Pointer operand;
};

}
}
}
}
#endif
