#include "RealConstantExpression.h"
#include <sstream>

using namespace thewizardplusplus::wizard_basic_2::compiler::translator;

RealConstantExpression::RealConstantExpression(float real_constant) :
	Expression(ValueType::NUMBER),
	real_constant(real_constant)
{}

std::string RealConstantExpression::getCppCode(void) const {
	std::ostringstream out;
	out << std::fixed << real_constant;

	return out.str();
}
