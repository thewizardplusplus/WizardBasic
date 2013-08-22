#include "AdditionType.h"
#include "../utils/assert.h"

using namespace thewizardplusplus::wizard_basic::compiler::translator;

char AdditionType::convertToCppCode(AdditionType::Types addition_type) {
	ASSERT(addition_type == ADDITION || addition_type == SUBTRACTION, "Wizard "
		"BASIC: translating error - invalid AdditionType value.");

	switch (addition_type) {
		case ADDITION:
			return '+';
		case SUBTRACTION:
			return '-';
	}

	// dummy for warning
	return '\0';
}

AdditionType::Types AdditionType::convertFromWizardBasicCode(const std::string&
	wizard_basic_code)
{
	ASSERT(wizard_basic_code == "+" || wizard_basic_code == "-", "Wizard BASIC:"
		" translating error - invalid code of addition operation; expected "
		"\"+\" or \"-\".");

	switch (wizard_basic_code[0]) {
		case '+':
			return ADDITION;
		case '-':
			return SUBTRACTION;
	}

	// dummy for warning
	return ADDITION;
}
