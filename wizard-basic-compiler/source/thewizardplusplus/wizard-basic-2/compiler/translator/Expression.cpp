#include "Expression.h"

using namespace thewizardplusplus::wizard_basic_2::compiler::translator;

Expression::Expression(ValueType::Types type) :
	type(type)
{}

Expression::~Expression(void) {}

ValueType::Types Expression::getType(void) const {
	return type;
}
