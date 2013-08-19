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

bool VariableList::hasVariable(const std::string& variable_name) {
	VariableInnerList::const_iterator i = variables.begin();
	for (; i != variables.end(); ++i) {
		if ((*i)->getName() == variable_name) {
			return true;
		}
	}

	return false;
}

void VariableList::addVariable(const shared_ptr<Variable>& variable) {
	if (!hasVariable(variable->getName())) {
		variables.push_back(variable);
	} else {
		throw DuplicateVariablesException(variable->getName());
	}
}

std::string VariableList::getCppDefinitionOfArraySizes(void) const {
	std::string cpp_definition;
	VariableInnerList::const_iterator i = variables.begin();
	for (; i != variables.end(); ++i) {
		Variable* variable = (*i).get();
		if (typeid(*variable) == typeid(ArrayVariable) || typeid(*variable) ==
			typeid(StringVariable))
		{
			cpp_definition += (format("\t%1%_SIZE = %2%,\n") % to_upper_copy(
				variable->getName()) % dynamic_cast<ArrayVariable*>(variable)->
				getSize()).str();
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

	return cpp_definition + "\n";
}
