#include "VariableList.h"
#include "exceptions/DuplicateVariablesException.h"
#include "ArrayVariable.h"
#include "StringVariable.h"
#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <typeinfo>

using namespace thewizardplusplus::wizard_basic::translator;
using namespace thewizardplusplus::wizard_basic::translator::exceptions;
using namespace boost;

bool VariableList::hasArrays(void) const {
	VariableInnerList::const_iterator i = variables.begin();
	for (; i != variables.end(); ++i) {
		shared_ptr<Variable> variable = *i;
		if (typeid(*variable) == typeid(ArrayVariable) || typeid(*variable) ==
			typeid(StringVariable))
		{
			return true;
		}
	}

	return false;
}

shared_ptr<Variable> VariableList::getVariableByName(const std::string&
	variable_name) const
{
	VariableInnerList::const_iterator i = variables.begin();
	for (; i != variables.end(); ++i) {
		shared_ptr<Variable> variable = *i;
		if (variable->getName() == variable_name) {
			return variable;
		}
	}

	return shared_ptr<Variable>();
}

void VariableList::addVariable(const shared_ptr<Variable>& variable) {
	if (!getVariableByName(variable->getName())) {
		variables.push_back(variable);
	} else {
		throw DuplicateVariablesException(variable->getName());
	}
}

std::string VariableList::getCppDefinitionOfArraySizes(void) const {
	std::string cpp_definition;
	VariableInnerList::const_iterator i = variables.begin();
	for (; i != variables.end(); ++i) {
		shared_ptr<Variable> variable = *i;
		if (typeid(*variable) == typeid(ArrayVariable) || typeid(*variable) ==
			typeid(StringVariable))
		{
			cpp_definition += (format("\t%1%_SIZE = %2%,\n") % to_upper_copy(
				variable->getName()) % dynamic_cast<ArrayVariable*>(variable.
				get())->getSize()).str();
		}
	}

	if (!cpp_definition.empty()) {
		cpp_definition = cpp_definition.substr(0, cpp_definition.length() - 2);
		return (format(
			"enum {\n"
			"%1%\n"
			"};\n\n"
		) % cpp_definition).str();
	} else {
		return "";
	}
}

std::string VariableList::getCppDefinitionOfVariables(void) const {
	std::string cpp_definition;
	VariableInnerList::const_iterator i = variables.begin();
	for (; i != variables.end(); ++i) {
		cpp_definition += (*i)->getCppDefinition();
	}

	if (!cpp_definition.empty()) {
		cpp_definition += "\n";
	}
	return cpp_definition;
}
