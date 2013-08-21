#include "IdentifierExpression.h"
#include "NumberVariable.h"
#include <typeinfo>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace boost;

IdentifierExpression::IdentifierExpression(const boost::shared_ptr<Variable>&
	variable)
:
	variable(variable)
{
	if (typeid(*variable) == typeid(NumberVariable)) {
		type = ValueType::NUMBER;
	} else {
		type = ValueType::ARRAY;
	}
}

std::string IdentifierExpression::getCppCode(void) const {
	return variable->getName();
}
