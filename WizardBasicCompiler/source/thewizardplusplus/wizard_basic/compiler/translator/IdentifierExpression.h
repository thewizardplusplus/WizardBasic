#ifndef IDENTIFIEREXPRESSION_H
#define IDENTIFIEREXPRESSION_H

#include "Expression.h"
#include "Variable.h"
#include <boost/shared_ptr.hpp>

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class IdentifierExpression : public Expression {
public:
	IdentifierExpression(const Variable::Pointer& variable);
	virtual std::string getCppCode(void) const;

private:
	Variable::Pointer variable;
};

}
}
}
}
#endif
