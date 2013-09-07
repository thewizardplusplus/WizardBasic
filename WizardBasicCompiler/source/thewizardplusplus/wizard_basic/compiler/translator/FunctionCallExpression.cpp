#include "FunctionCallExpression.h"

using namespace thewizardplusplus::wizard_basic::compiler::translator;

FunctionCallExpression::FunctionCallExpression(const Function& function) :
	Expression(function.getResultType()),
	function(function)
{}

std::string FunctionCallExpression::getCppCode(void) const {
	return function.getCppCode();
}
