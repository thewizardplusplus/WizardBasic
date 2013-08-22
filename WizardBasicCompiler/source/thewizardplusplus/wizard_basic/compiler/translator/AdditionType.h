#ifndef ADDITIONTYPE_H
#define ADDITIONTYPE_H

#include <string>

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace translator {

class AdditionType {
public:
	enum Types {
		ADDITION,
		SUBTRACTION
	};

	static char convertToCppCode(AdditionType::Types addition_type);
	static AdditionType::Types convertFromWizardBasicCode(const std::string&
		wizard_basic_code);
};

}
}
}
}
#endif
