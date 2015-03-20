#ifndef OUTOFBOUNDSEXCEPTION_H
#define OUTOFBOUNDSEXCEPTION_H

#include "BaseException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace base {
namespace exceptions {

class OutOfBoundsException : public BaseException {
public:
	OutOfBoundsException(const std::string& array_name, size_t array_size,
		float rounded_index);
};

}
}
}
}
}
#endif
