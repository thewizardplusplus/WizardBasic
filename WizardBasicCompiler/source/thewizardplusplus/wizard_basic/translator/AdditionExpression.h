#ifndef ADDITIONEXPRESSION_H
#define ADDITIONEXPRESSION_H

#include "Expression.h"
#include "AdditionType.h"
#include <boost/shared_ptr.hpp>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class AdditionExpression : public Expression {
public:
	AdditionExpression(boost::shared_ptr<Expression> operand1, AdditionType::
		Types addition_type, boost::shared_ptr<Expression> operand2);
	virtual std::string getCppCode(void) const;

private:
	boost::shared_ptr<Expression> operand1;
	AdditionType::Types           addition_type;
	boost::shared_ptr<Expression> operand2;
};

}
}
}
#endif
