#include "ParenthesesExpression.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace boost;

ParenthesesExpression::ParenthesesExpression(shared_ptr<Expression> operand) :
	Expression(operand->getType()),
	operand(operand)
{}

std::string ParenthesesExpression::getCppCode(void) const {
	return (format("(%1%)") % operand->getCppCode()).str();
}
