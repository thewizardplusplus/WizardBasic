#include "FunctionList.h"
#include "exceptions/UnknownFunctionException.h"
#include <boost/assign/list_of.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost::assign;

FunctionList::FunctionList(void) :
	functions(list_of
		(Function(ValueType::VOID, "Test"))
		(Function(ValueType::NUMBER, "Test1", "TST", list_of
			(FunctionParameter(ValueType::NUMBER))
			.convert_to_container<Function::ParameterList>()))
		(Function(ValueType::VOID, "Test2", "", list_of
			(FunctionParameter(ValueType::NUMBER))
			(FunctionParameter(ValueType::ARRAY))
			.convert_to_container<Function::ParameterList>()))
		.convert_to_container<FunctionInnerList>())
{}

Function FunctionList::getFunctionByName(const std::string& name) const {
	FunctionInnerList::const_iterator i = functions.begin();
	for (; i != functions.end(); ++i) {
		Function function = *i;
		if (function.getName() == name || (!function.getAlias().empty() &&
			function.getAlias() == name))
		{
			return function;
		}
	}

	throw UnknownFunctionException(name);
}
