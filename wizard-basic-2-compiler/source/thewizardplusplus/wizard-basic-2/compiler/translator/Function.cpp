#include "Function.h"
#include "../utils/assert.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic_2::compiler::translator;
using namespace boost;

Function::Function(const std::string& name) :
	result_type(ValueType::UNKNOWN_TYPE),
	name(name)
{}

Function::Function(ValueType::Types result_type, const std::string& name, const
	std::string& cpp_name, const ParameterList& parameters)
:
	result_type(result_type),
	name(name),
	cpp_name(cpp_name),
	parameters(parameters)
{}

bool Function::operator==(const Function& function) const {
	if (name != function.name) {
		return false;
	}

	if (parameters.size() != function.parameters.size()) {
		return false;
	}

	ParameterList::const_iterator i = parameters.begin();
	ParameterList::const_iterator j = function.parameters.begin();
	for (; i != parameters.end() && j != function.parameters.end(); ++i, ++j) {
		if ((*i).getType() != (*j).getType()) {
			return false;
		}
	}

	return true;
}

ValueType::Types Function::getResultType(void) const {
	return result_type;
}

std::string Function::getName(void) const {
	return name;
}

std::string Function::getCppName(void) const {
	return cpp_name;
}

const Function::ParameterList& Function::getParameters(void) const {
	return parameters;
}

Function::ParameterList& Function::getParameters(void) {
	return parameters;
}

std::string Function::getDescription(void) const {
	return toString(FunctionStringFormat::DESCRIPTION);
}

std::string Function::getCppCode(void) const {
	return toString(FunctionStringFormat::CPP_CODE);
}

std::string Function::toString(FunctionStringFormat::Types string_format) const
{
	ASSERT(string_format == FunctionStringFormat::DESCRIPTION || string_format
		== FunctionStringFormat::CPP_CODE, "Wizard BASIC 2: translating "
		"error - invalid FunctionStringFormat type.");

	std::string parameters_string;
	ParameterList::const_iterator i = parameters.begin();
	for (; i != parameters.end(); ++i) {
		switch (string_format) {
			case FunctionStringFormat::DESCRIPTION:
				parameters_string += ValueType::convertToString((*i).
					getType());
				break;
			case FunctionStringFormat::CPP_CODE:
				parameters_string += (*i).getCppCode();
				break;
		}
		parameters_string += ", ";
	}
	if (!parameters_string.empty()) {
		parameters_string = parameters_string.substr(0, parameters_string.
			length() - 2);
	}

	switch (string_format) {
		case FunctionStringFormat::DESCRIPTION:
			return (format("%1%(%2%)") % name % parameters_string).str();
		case FunctionStringFormat::CPP_CODE:
			return (format("%1%(%2%)") % cpp_name % parameters_string).str();
	}

	// dummy for warning, value selected for guarantee error in generated
	// C++-code
	return "Function()";
}
