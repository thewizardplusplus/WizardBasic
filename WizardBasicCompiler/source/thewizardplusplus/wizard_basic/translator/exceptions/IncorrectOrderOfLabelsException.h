#ifndef INCORRECTORDEROFLABELSEXCEPTION_H
#define INCORRECTORDEROFLABELSEXCEPTION_H

#include "TranslateException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace translator {
namespace exceptions {

class IncorrectOrderOfLabelsException : public TranslateException {
public:
	IncorrectOrderOfLabelsException(void);
};

}
}
}
}
#endif
