#include "IdentifierExpression.h"
#include "NumberVariable.h"
#include "ArrayVariable.h"
#include "StringVariable.h"
#include <typeinfo>

using namespace thewizardplusplus::wizard_basic_2::compiler::translator;
using namespace boost;

IdentifierExpression::IdentifierExpression(const Variable::Pointer& variable) :
	variable(variable)
{
	if (typeid(*variable) == typeid(NumberVariable)) {
		type = ValueType::NUMBER;
	} else if (typeid(*variable) == typeid(ArrayVariable) || typeid(*variable)
		== typeid(StringVariable))
	{
		type = ValueType::ARRAY;
	}
}

std::string IdentifierExpression::getCppCode(void) const {
	return variable->getName();
}
