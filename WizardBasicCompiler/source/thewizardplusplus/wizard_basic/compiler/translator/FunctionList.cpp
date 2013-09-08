#include "FunctionList.h"
#include "exceptions/UnknownFunctionException.h"
#include <boost/assign/list_of.hpp>

using namespace thewizardplusplus::wizard_basic::compiler::translator;
using namespace thewizardplusplus::wizard_basic::compiler::translator::
	exceptions;
using namespace boost::assign;

FunctionList::FunctionList(void) {
	functions = list_of
		(Function(ValueType::NUMBER, "TEST", "Test", list_of
			(FunctionParameter(ValueType::NUMBER))
		)
	);
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
