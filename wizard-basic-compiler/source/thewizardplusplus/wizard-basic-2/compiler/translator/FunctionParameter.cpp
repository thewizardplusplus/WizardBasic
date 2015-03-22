#include "FunctionParameter.h"

using namespace thewizardplusplus::wizard_basic_2::compiler::translator;

FunctionParameter::FunctionParameter(ValueType::Types type) :
	type(type)
{}

FunctionParameter::FunctionParameter(Expression::Pointer expression) :
	type(expression->getType()),
	expression(expression)
{}

ValueType::Types FunctionParameter::getType(void) const {
	return type;
}

std::string FunctionParameter::getCppCode(void) const {
	return expression->getCppCode();
}
