#ifndef ADDITIONEXPRESSION_H
#define ADDITIONEXPRESSION_H

#include "Expression.h"
#include "AdditionType.h"
#include <boost/shared_ptr.hpp>

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace translator {

class AdditionExpression : public Expression {
public:
	AdditionExpression(Expression::Pointer operand1, AdditionType::Types
		addition_type, Expression::Pointer operand2);
	virtual std::string getCppCode(void) const;

private:
	Expression::Pointer operand1;
	AdditionType::Types addition_type;
	Expression::Pointer operand2;
};

}
}
}
}
#endif
