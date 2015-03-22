#include "ValueType.h"
#include "../utils/assert.h"

using namespace thewizardplusplus::wizard_basic_2::compiler::translator;

std::string ValueType::convertToString(ValueType::Types value_type) {
	ASSERT(value_type == UNKNOWN_TYPE || value_type == VOID || value_type ==
		NUMBER || value_type == ARRAY, "Wizard BASIC 2: translating error - "
		"invalid ValueType value.");

	switch (value_type) {
		case VOID:
			return "VOID";
		case NUMBER:
			return "NUMBER";
		case ARRAY:
			return "ARRAY";
		default:
			return "UNKNOWN_TYPE";
	}
}
