#ifndef PARENTHESESEXPRESSION_H
#define PARENTHESESEXPRESSION_H

#include "Expression.h"
#include <boost/shared_ptr.hpp>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class ParenthesesExpression : public Expression {
public:
	ParenthesesExpression(boost::shared_ptr<Expression> operand);
	virtual std::string getCppCode(void) const;

private:
	boost::shared_ptr<Expression> operand;
};

}
}
}
#endif
