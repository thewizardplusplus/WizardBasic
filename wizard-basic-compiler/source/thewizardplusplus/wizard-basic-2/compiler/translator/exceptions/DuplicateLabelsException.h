#ifndef DUPLICATELABELSEXCEPTION_H
#define DUPLICATELABELSEXCEPTION_H

#include "TranslateException.h"

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace compiler {
namespace translator {
namespace exceptions {

class DuplicateLabelsException : public TranslateException {
public:
	DuplicateLabelsException(void);
};

}
}
}
}
}
#endif
