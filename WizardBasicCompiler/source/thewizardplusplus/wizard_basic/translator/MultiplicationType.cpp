#include "MultiplicationType.h"
#include "../utils/assert.h"

using namespace thewizardplusplus::wizard_basic::translator;

char MultiplicationType::convertToCppCode(MultiplicationType::Types
	multiplication_type)
{
	ASSERT(multiplication_type == MULTIPLICATION || multiplication_type ==
		DIVISION, "Wizard BASIC: translating error - invalid MultiplicationType"
		" value.");

	switch (multiplication_type) {
		case MULTIPLICATION:
			return '*';
		case DIVISION:
			return '/';
	}

	// dummy for warning, value selected for guarantee error in generated C-code
	return '@';
}

MultiplicationType::Types MultiplicationType::convertFromWizardBasicCode(const
	std::string& wizard_basic_code)
{
	ASSERT(wizard_basic_code == "*" || wizard_basic_code == "/", "Wizard BASIC:"
		" translating error - invalid code of addition operation; expected "
		"\"*\" or \"/\".");

	switch (wizard_basic_code[0]) {
		case '*':
			return MULTIPLICATION;
		case '/':
			return DIVISION;
	}

	// dummy for warning
	return MULTIPLICATION;
}
