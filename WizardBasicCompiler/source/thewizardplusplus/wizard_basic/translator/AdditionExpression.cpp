#include "AdditionExpression.h"
#include "exceptions/IllegalAdditionOperationException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

AdditionExpression::AdditionExpression(shared_ptr<Expression> operand1,
	AdditionType::Types addition_type, shared_ptr<Expression> operand2)
:
	operand1(operand1),
	addition_type(addition_type),
	operand2(operand2)
{
	if (operand1->getType() != operand2->getType() || (operand1->getType() !=
		ValueType::NUMBER && operand1->getType() != ValueType::ARRAY) ||
		(operand1->getType() == ValueType::ARRAY && addition_type !=
		AdditionType::ADDITION))
	{
		throw IllegalAdditionOperationException(addition_type, operand1->
			getType(), operand2->getType());
	}

	type = operand1->getType();
}

std::string AdditionExpression::getCppCode(void) const {
	return (format("%1% %2% %3%") % operand1->getCppCode() % AdditionType::
		convertToCppCode(addition_type) % operand2->getCppCode()).str();
}
