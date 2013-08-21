#ifndef IDENTIFIEREXPRESSION_H
#define IDENTIFIEREXPRESSION_H

#include "Expression.h"
#include "Variable.h"
#include <boost/shared_ptr.hpp>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class IdentifierExpression : public Expression {
public:
	IdentifierExpression(const boost::shared_ptr<Variable>& variable);
	virtual std::string getCppCode(void) const;

private:
	boost::shared_ptr<Variable> variable;
};

}
}
}
#endif
