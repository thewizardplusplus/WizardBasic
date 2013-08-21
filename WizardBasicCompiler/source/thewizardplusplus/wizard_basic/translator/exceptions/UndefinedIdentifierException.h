#ifndef UNDEFINEDIDENTIFIEREXCEPTION_H
#define UNDEFINEDIDENTIFIEREXCEPTION_H

#include "TranslateException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {
namespace exceptions {

class UndefinedIdentifierException : public TranslateException {
public:
	UndefinedIdentifierException(const std::string& identifier);
};

}
}
}
}
#endif
