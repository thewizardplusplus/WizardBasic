#ifndef FAILEDOPENTEMPORARYFILEEXCEPTION_H
#define FAILEDOPENTEMPORARYFILEEXCEPTION_H

#include "CompilerException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace compiler {
namespace exceptions {

class FailedOpenTemporaryFileException : public CompilerException {
public:
	FailedOpenTemporaryFileException(const std::string& filename);
};

}
}
}
}
}
#endif
