#include "VariableList.h"
#include "exceptions/DuplicateVariablesException.h"
#include "ArrayVariable.h"
#include "StringVariable.h"
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <typeinfo>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost;

Variable::Pointer VariableList::getVariableByName(const std::string&
	variable_name) const
{
	VariableInnerList::const_iterator i = variables.begin();
	for (; i != variables.end(); ++i) {
		Variable::Pointer variable = *i;
		if (variable->getName() == variable_name) {
			return variable;
		}
	}

	return Variable::Pointer();
}

bool VariableList::hasArrays(void) const {
	VariableInnerList::const_iterator i = variables.begin();
	for (; i != variables.end(); ++i) {
		Variable::Pointer variable = *i;
		if (typeid(*variable) == typeid(ArrayVariable) || typeid(*variable) ==
			typeid(StringVariable))
		{
			return true;
		}
	}

	return false;
}

void VariableList::addVariable(const Variable::Pointer& variable) {
	if (!getVariableByName(variable->getName())) {
		variables.push_back(variable);
	} else {
		throw DuplicateVariablesException(variable->getName());
	}
}

std::string VariableList::getCppDefinition(void) const {
	std::string cpp_definition;
	VariableInnerList::const_iterator i = variables.begin();
	for (; i != variables.end(); ++i) {
		cpp_definition += (*i)->getCppDefinition();
	}

	if (!cpp_definition.empty()) {
		return cpp_definition + "\n";
	} else {
		return "";
	}
}
