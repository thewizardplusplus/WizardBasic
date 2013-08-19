#ifndef CONDITIONTYPE_H
#define CONDITIONTYPE_H

#include <string>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class ConditionType {
public:
	enum Types {
		EQUAL,
		LESS,
		GREATER
	};

	static std::string convertToCppCode(ConditionType::Types condition_type);
	static ConditionType::Types convertFromWizardBasicCode(const std::string&
		wizard_basic_code);
};

}
}
}
#endif
