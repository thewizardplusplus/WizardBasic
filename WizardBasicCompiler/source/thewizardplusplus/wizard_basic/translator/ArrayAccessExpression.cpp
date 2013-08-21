#include "ArrayAccessExpression.h"
#include "NumberVariable.h"
#include "ArrayVariable.h"
#include "StringVariable.h"
#include "exceptions/IllegalArrayAccessOperationException.h"
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <typeinfo>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

ArrayAccessExpression::ArrayAccessExpression(const boost::shared_ptr<Variable>&
	variable, const boost::shared_ptr<Expression>& index, const std::string&
	index_variable_name)
:
	Expression(ValueType::NUMBER),
	variable(variable),
	index_variable_name(index_variable_name)
{
	ValueType::Types variable_type = ValueType::UNKNOWN_TYPE;
	if (typeid(*variable) == typeid(NumberVariable)) {
		variable_type = ValueType::NUMBER;
	} else if (typeid(*variable) == typeid(ArrayVariable) || typeid(*variable)
		== typeid(StringVariable))
	{
		variable_type = ValueType::ARRAY;
	}

	if (variable_type != ValueType::ARRAY || index->getType() != ValueType::
		NUMBER)
	{
		throw IllegalArrayAccessOperationException(variable_type, index->
			getType());
	}
}

std::string ArrayAccessExpression::getCppCode(void) const {
	return (format("%1%[%2%]") % variable->getName() % index_variable_name).
		str();
}
