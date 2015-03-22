#include "ConditionType.h"
#include "../utils/assert.h"

using namespace thewizardplusplus::wizard_basic_2::compiler::translator;

std::string ConditionType::convertToCppCode(ConditionType::Types condition_type)
{
	ASSERT(condition_type == EQUAL || condition_type == LESS || condition_type
		== GREATER, "Wizard BASIC 2: translating error - invalid ConditionType "
		"value.");

	switch (condition_type) {
		case EQUAL:
			return "==";
		case LESS:
			return "<";
		case GREATER:
			return ">";
	}

	// dummy for warning, value selected for guarantee error in generated
	// C++-code
	return "@";
}

ConditionType::Types ConditionType::convertFromWizardBasicCode(const std::
	string& wizard_basic_code)
{
	ASSERT(wizard_basic_code == "=" || wizard_basic_code == "<" ||
		wizard_basic_code == ">", "Wizard BASIC 2: translating error - invalid "
		"code of condition; expected \"=\", \"<\" or \">\".");

	switch (wizard_basic_code[0]) {
		case '=':
			return EQUAL;
		case '<':
			return LESS;
		case '>':
			return GREATER;
	}

	// dummy for warning
	return EQUAL;
}
