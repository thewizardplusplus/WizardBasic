#ifndef MULTIPLICATIONEXPRESSION_H
#define MULTIPLICATIONEXPRESSION_H

#include "Expression.h"
#include "MultiplicationType.h"
#include <boost/shared_ptr.hpp>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class MultiplicationExpression : public Expression {
public:
	MultiplicationExpression(boost::shared_ptr<Expression> operand1,
		MultiplicationType::Types multiplication_type, boost::shared_ptr<
		Expression> operand2);
	virtual std::string getCppCode(void) const;

private:
	boost::shared_ptr<Expression> operand1;
	MultiplicationType::Types     multiplication_type;
	boost::shared_ptr<Expression> operand2;
};

}
}
}
#endif
