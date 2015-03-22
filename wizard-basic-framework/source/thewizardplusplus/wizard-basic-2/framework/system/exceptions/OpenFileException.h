#ifndef OPENFILEEXCEPTION_H
#define OPENFILEEXCEPTION_H

#include "SystemException.h"

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace framework {
namespace system {
namespace exceptions {

class OpenFileException : public SystemException {
public:
	OpenFileException(const std::string& filename);
};

}
}
}
}
}
#endif
