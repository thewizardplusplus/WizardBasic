#include "UnknownFunctionException.h"
#include <boost/format.hpp>

using namespace thewizardplusplus::wizard_basic_2::compiler::translator::
	exceptions;
using namespace thewizardplusplus::wizard_basic_2::compiler::translator;
using namespace boost;

UnknownFunctionException::UnknownFunctionException(const Function&
	searched_function, const FunctionList::SimpleFunctionList& finded_functions)
:
	IllegalFunctionCallOperationException(prepareExceptionDescription(
		searched_function, finded_functions))
{}

std::string UnknownFunctionException::prepareExceptionDescription(const
	Function& searched_function, const FunctionList::SimpleFunctionList&
	finded_functions) const
{
	size_t number_of_finded_functions = finded_functions.size();
	if (number_of_finded_functions == 0) {
		return (format("unknown function %1%") % searched_function.
			getDescription()).str();
	}

	std::string finded_functions_description;
	FunctionList::SimpleFunctionList::const_iterator i = finded_functions.
		begin();
	size_t number_of_penult = number_of_finded_functions - 1;
	size_t counter = 1;
	for (; i != finded_functions.end(); ++i, counter++) {
		finded_functions_description += (*i).getDescription();
		if (counter < number_of_penult) {
			finded_functions_description += ", ";
		} else if (counter == number_of_penult) {
			finded_functions_description += " and ";
		}
	}

	return (format("unknown function %1%, finded %2%") % searched_function.
		getDescription() % finded_functions_description).str();
}
