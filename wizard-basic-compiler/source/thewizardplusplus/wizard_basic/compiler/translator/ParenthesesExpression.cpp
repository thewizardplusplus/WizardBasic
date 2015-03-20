#include "ParenthesesExpression.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace boost;

ParenthesesExpression::ParenthesesExpression(const Expression::Pointer& operand)
:
	Expression(operand->getType()),
	operand(operand)
{}

std::string ParenthesesExpression::getCppCode(void) const {
	return (format("(%1%)") % operand->getCppCode()).str();
}
