#include "FunctionParameter.h"
#include "exceptions/IncorrectTypesOfFunctionParameterException.h"

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;

FunctionParameter::FunctionParameter(ValueType::Types type) :
	type(type)
{}

ValueType::Types FunctionParameter::getType(void) const {
	return type;
}

void FunctionParameter::setExpression(const Expression::Pointer& expression) {
	ValueType::Types expression_type = expression->getType();
	if (expression_type != type) {
		throw IncorrectTypesOfFunctionParameterException(type, expression_type);
	}

	this->expression = expression;
}

std::string FunctionParameter::getCppCode(void) const {
	return expression->getCppCode();
}
