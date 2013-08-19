#include "ConditionType.h"
#include "../utils/assert.h"

using namespace thewizardplusplus::wizard_basic::translator;

std::string ConditionType::convertToCppCode(ConditionType::Types
	condition_type)
{
	ASSERT(condition_type == EQUAL || condition_type == LESS || condition_type
		== GREATER, "Wizard BASIC: translating error - invalid ConditionType "
		"value.");
	switch (condition_type) {
		case ConditionType::EQUAL:
			return "==";
			break;
		case ConditionType::LESS:
			return "<";
			break;
		case ConditionType::GREATER:
			return ">";
			break;
	}

	// dummy for warning, value selected for guarantee error in generated C-code
	return "@";
}

ConditionType::Types ConditionType::convertFromWizardBasicCode(const std::
	string& wizard_basic_code)
{
	ASSERT(wizard_basic_code == "=" || wizard_basic_code == "<" ||
		wizard_basic_code == ">", "Wizard BASIC: translating error - invalid "
		"code of condition; expected \"=\", \"<\" or \">\".");
	switch (wizard_basic_code[0]) {
		case '=':
			return ConditionType::EQUAL;
			break;
		case '<':
			return ConditionType::LESS;
			break;
		case '>':
			return ConditionType::GREATER;
			break;
	}

	// dummy for warning
	return ConditionType::EQUAL;
}
