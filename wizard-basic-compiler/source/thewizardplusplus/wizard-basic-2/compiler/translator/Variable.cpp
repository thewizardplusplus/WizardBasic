#include "Variable.h"

using namespace thewizardplusplus::wizard_basic_2::compiler::translator;

Variable::Variable(const std::string& name) :
	name(name)
{}

Variable::~Variable(void) {}

std::string Variable::getName(void) const {
	return name;
}
