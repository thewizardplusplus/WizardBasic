#include "MultiplicationExpression.h"
#include "exceptions/IllegalMultiplicationOperationException.h"
#include "AdditionExpression.h"
#include "ParenthesesExpression.h"
#include <boost/format.hpp>
#include <typeinfo>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost;

MultiplicationExpression::MultiplicationExpression(const Expression::Pointer&
	operand1, MultiplicationType::Types multiplication_type, const Expression::
	Pointer& operand2)
:
	Expression(ValueType::NUMBER),
	operand1(operand1),
	multiplication_type(multiplication_type),
	operand2(operand2)
{
	if (operand1->getType() != operand2->getType() || operand1->getType() !=
		ValueType::NUMBER)
	{
		throw IllegalMultiplicationOperationException(multiplication_type,
			operand1->getType(), operand2->getType());
	}

	this->operand1 = Expression::Pointer(new ParenthesesExpression(operand1));
	this->operand2 = Expression::Pointer(new ParenthesesExpression(operand2));
}

std::string MultiplicationExpression::getCppCode(void) const {
	return (format("%1% %2% %3%") % operand1->getCppCode() % MultiplicationType
		::convertToCppCode(multiplication_type) % operand2->getCppCode()).str();
}
