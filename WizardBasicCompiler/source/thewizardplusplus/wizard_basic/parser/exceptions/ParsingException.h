#ifndef PARSINGEXCEPTION_H
#define PARSINGEXCEPTION_H

#include "../../exceptions/WizardBasicException.h"
#include "CodePosition.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace parser {
namespace exceptions {

class ParsingException : public thewizardplusplus::wizard_basic::exceptions::
	WizardBasicException
{
public:
	ParsingException(const CodePosition& code_position);

private:
	static const std::string MESSAGE;
};

}
}
}
}
#endif
