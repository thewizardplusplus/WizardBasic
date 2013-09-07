#include "Function.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace boost;

Function::Function(ValueType::Types result_type, const std::string& name, const
	std::string& alias, const ParameterList& parameters)
:
	result_type(result_type),
	name(name),
	alias(alias),
	parameters(parameters)
{}

ValueType::Types Function::getResultType(void) const {
	return result_type;
}

std::string Function::getName(void) const {
	return name;
}

std::string Function::getAlias(void) const {
	return alias;
}

Function::ParameterList Function::getParameters(void) {
	return parameters;
}

std::string Function::getCppCode(void) const {
	std::string parameters_code;
	ParameterList::const_iterator i = parameters.begin();
	for (; i != parameters.end(); ++i) {
		parameters_code += (*i).getCppCode() + ", ";
	}
	if (!parameters_code.empty()) {
		parameters_code = parameters_code.substr(0, parameters_code.length() -
			2);
	}

	return (format("%1%(%2%)") % name % parameters_code).str();
}
