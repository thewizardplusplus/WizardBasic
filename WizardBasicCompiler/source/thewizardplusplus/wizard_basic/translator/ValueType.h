#ifndef VALUETYPE_H
#define VALUETYPE_H

#include <string>

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {

class ValueType {
public:
	enum Types {
		UNKNOWN_TYPE,
		VOID,
		NUMBER,
		ARRAY
	};

	static std::string convertToString(ValueType::Types value_type);
};

}
}
}
#endif
