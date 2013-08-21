#include "FunctionCallExpression.h"

using namespace thewizardplusplus::wizard_basic::translator;

FunctionCallExpression::FunctionCallExpression(void) :
	Expression(ValueType::NUMBER)
{}

std::string FunctionCallExpression::getCppCode(void) const {
	return "<function_call>";
}
