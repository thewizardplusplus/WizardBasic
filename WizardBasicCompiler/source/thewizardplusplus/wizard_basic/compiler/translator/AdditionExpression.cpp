#include "AdditionExpression.h"
#include "exceptions/IllegalAdditionOperationException.h"
#include "ParenthesesExpression.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost;

AdditionExpression::AdditionExpression(Expression::Pointer operand1,
	AdditionType::Types addition_type, Expression::Pointer operand2)
:
	Expression(ValueType::NUMBER),
	operand1(operand1),
	addition_type(addition_type),
	operand2(operand2)
{
	if (operand1->getType() != operand2->getType() || operand1->getType() !=
		ValueType::NUMBER)
	{
		throw IllegalAdditionOperationException(addition_type, operand1->
			getType(), operand2->getType());
	}

	this->operand1 = Expression::Pointer(new ParenthesesExpression(operand1));
	this->operand2 = Expression::Pointer(new ParenthesesExpression(operand2));
}

std::string AdditionExpression::getCppCode(void) const {
	return (format("%1% %2% %3%") % operand1->getCppCode() % AdditionType::
		convertToCppCode(addition_type) % operand2->getCppCode()).str();
}
