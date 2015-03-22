#ifndef COMPILEREXCEPTION_H
#define COMPILEREXCEPTION_H

#include "../../exceptions/WizardBasicCompilerException.h"

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace compiler {
namespace exceptions {

class CompilerException : public wizard_basic_2::compiler::exceptions::
	WizardBasicCompilerException
{
public:
	CompilerException(const std::string& message);
	//virtual ~CompilerException(void) throw();
};

}
}
}
}
}
#endif
