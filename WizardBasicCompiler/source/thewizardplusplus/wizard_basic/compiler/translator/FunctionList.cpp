#include "FunctionList.h"
#include "exceptions/UnknownFunctionException.h"
#include <boost/assign/list_of.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost::assign;

FunctionList::FunctionList(void) {
	functions = list_of
		(Function(ValueType::NUMBER, "RND", "System::getInstance()."
			"getRandomNumber"))
		(Function(ValueType::NUMBER, "TIMER", "System::getInstance()."
			"getTimeFromStartInS"))
		(Function(ValueType::VOID, "TRACEN", "System::getInstance().trace",
			list_of
				(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::VOID, "TRACES", "System::getInstance().trace",
			list_of
				(FunctionParameter(ValueType::ARRAY))));
}

Function FunctionList::getFunctionByAlias(const std::string& alias) const {
	FunctionInnerList::const_iterator i = functions.begin();
	for (; i != functions.end(); ++i) {
		Function function = *i;
		if (function.getAlias() == alias) {
			return function;
		}
	}

	throw UnknownFunctionException();
}
