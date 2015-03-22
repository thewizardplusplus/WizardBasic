#include "ArrayAccessExpression.h"
#include "NumberVariable.h"
#include "ArrayVariable.h"
#include "StringVariable.h"
#include "exceptions/IllegalArrayAccessOperationException.h"
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <typeinfo>

using namespace thewizardplusplus::wizard_basic_2::compiler::translator;
using namespace thewizardplusplus::wizard_basic_2::compiler::translator::
	exceptions;
using namespace boost;

ArrayAccessExpression::ArrayAccessExpression(const Variable::Pointer& variable,
	const Expression::Pointer& index_expression)
:
	Expression(ValueType::NUMBER),
	variable(variable),
	index_expression(index_expression)
{
	ValueType::Types variable_type = ValueType::UNKNOWN_TYPE;
	if (typeid(*variable) == typeid(NumberVariable)) {
		variable_type = ValueType::NUMBER;
	} else if (typeid(*variable) == typeid(ArrayVariable) || typeid(*variable)
		== typeid(StringVariable))
	{
		variable_type = ValueType::ARRAY;
	}

	if (variable_type != ValueType::ARRAY || index_expression->getType() !=
		ValueType::NUMBER)
	{
		throw IllegalArrayAccessOperationException(variable_type,
			index_expression->getType());
	}
}

std::string ArrayAccessExpression::getCppCode(void) const {
	return (format("%1%[%2%]") % variable->getName() % index_expression->
		getCppCode()).str();
}
