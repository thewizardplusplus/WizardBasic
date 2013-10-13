#ifndef INVALIDFILEIDEXCEPTION_H
#define INVALIDFILEIDEXCEPTION_H

#include "SystemException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace system {
namespace exceptions {

class InvalidFileIdException : public SystemException {
public:
	InvalidFileIdException(float file_id);
};

}
}
}
}
}
#endif
