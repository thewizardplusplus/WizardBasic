#include "MultiplicationExpression.h"
#include "exceptions/IllegalMultiplicationOperationException.h"
#include "AdditionExpression.h"
#include "ParenthesesExpression.h"
#include <boost/format.hpp>
#include <typeinfo>

#include <iostream>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

MultiplicationExpression::MultiplicationExpression(shared_ptr<Expression>
	operand1, MultiplicationType::Types multiplication_type, shared_ptr<
	Expression> operand2)
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

	if (typeid(*operand1) == typeid(AdditionExpression)) {
		this->operand1 = shared_ptr<Expression>(new ParenthesesExpression(
			operand1));
	}
	if (typeid(*operand2) == typeid(AdditionExpression)) {
		this->operand2 = shared_ptr<Expression>(new ParenthesesExpression(
			operand2));
	}
}

std::string MultiplicationExpression::getCppCode(void) const {
	return (format("%1% %2% %3%") % operand1->getCppCode() % MultiplicationType
		::convertToCppCode(multiplication_type) % operand2->getCppCode()).str();
}
