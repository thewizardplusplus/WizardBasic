#ifndef ASSEMBLINGORLINKINGEXCEPTION_H
#define ASSEMBLINGORLINKINGEXCEPTION_H

#include "CompilerException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace compiler {
namespace exceptions {

class AssemblingOrLinkingException : public CompilerException {
public:
	AssemblingOrLinkingException(void);
};

}
}
}
}
}
#endif
