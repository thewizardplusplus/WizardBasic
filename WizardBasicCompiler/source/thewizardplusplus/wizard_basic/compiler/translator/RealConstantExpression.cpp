#include "RealConstantExpression.h"
#include <boost/lexical_cast.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace boost;

RealConstantExpression::RealConstantExpression(float real_constant) :
	Expression(ValueType::NUMBER),
	real_constant(real_constant)
{}

std::string RealConstantExpression::getCppCode(void) const {
	return lexical_cast<std::string>(real_constant);
}
