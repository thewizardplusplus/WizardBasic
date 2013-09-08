#include "FunctionList.h"
#include "exceptions/UnknownFunctionException.h"
#include <boost/assign/list_of.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost::assign;

FunctionList::FunctionList(void) {
	functions = list_of
		// math module
		(Function(ValueType::NUMBER, "SIN", "std::sin", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "COS", "std::cos", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "TAN", "std::tan", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "ATN", "std::atan", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "EXP", "std::exp", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "LOG", "std::log", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "SQR", "std::sqrt", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "ABS", "std::abs", list_of
			(FunctionParameter(ValueType::NUMBER))))
		(Function(ValueType::NUMBER, "INT", "std::floor", list_of
			(FunctionParameter(ValueType::NUMBER))))
		// system module
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
