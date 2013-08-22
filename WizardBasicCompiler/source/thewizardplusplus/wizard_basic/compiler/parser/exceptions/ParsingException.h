#ifndef PARSINGEXCEPTION_H
#define PARSINGEXCEPTION_H

#include "../../exceptions/WizardBasicCompilerException.h"
#include "CodePosition.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace compiler {
namespace parser {
namespace exceptions {

class ParsingException : public compiler::exceptions::
	WizardBasicCompilerException
{
public:
	ParsingException(const CodePosition& code_position);
};

}
}
}
}
}
#endif
