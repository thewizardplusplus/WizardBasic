#ifndef ARRAYACCESSEXPRESSION_H
#define ARRAYACCESSEXPRESSION_H

#include "Expression.h"
#include "Variable.h"
#include <boost/shared_ptr.hpp>

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class ArrayAccessExpression : public Expression {
public:
	ArrayAccessExpression(const Variable::Pointer& variable, const Expression::
		Pointer& index_expression);
	virtual std::string getCppCode(void) const;

private:
	Variable::Pointer   variable;
	Expression::Pointer index_expression;
};

}
}
}
}
#endif
