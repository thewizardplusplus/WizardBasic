#ifndef MULTIPLICATIONEXPRESSION_H
#define MULTIPLICATIONEXPRESSION_H

#include "Expression.h"
#include "MultiplicationType.h"
#include <boost/shared_ptr.hpp>

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class MultiplicationExpression : public Expression {
public:
	MultiplicationExpression(const Expression::Pointer& operand1,
		MultiplicationType::Types multiplication_type, const Expression::
		Pointer& operand2);
	virtual std::string getCppCode(void) const;

private:
	Expression::Pointer       operand1;
	MultiplicationType::Types multiplication_type;
	Expression::Pointer       operand2;
};

}
}
}
}
#endif
