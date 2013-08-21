#ifndef ARRAYACCESSEXPRESSION_H
#define ARRAYACCESSEXPRESSION_H

#include "Expression.h"
#include "Variable.h"
#include <boost/shared_ptr.hpp>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class ArrayAccessExpression : public Expression {
public:
	ArrayAccessExpression(const boost::shared_ptr<Variable>& variable, const
		boost::shared_ptr<Expression>& index, const std::string&
		index_variable_name);
	virtual std::string getCppCode(void) const;

private:
	boost::shared_ptr<Variable> variable;
	std::string                 index_variable_name;
};

}
}
}
#endif
