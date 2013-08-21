#ifndef MULTIPLICATIONTYPE_H
#define MULTIPLICATIONTYPE_H

#include <string>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class MultiplicationType {
public:
	enum Types {
		MULTIPLICATION,
		DIVISION
	};

	static char convertToCppCode(MultiplicationType::Types multiplication_type);
	static MultiplicationType::Types convertFromWizardBasicCode(const std::
		string& wizard_basic_code);
};

}
}
}
#endif
