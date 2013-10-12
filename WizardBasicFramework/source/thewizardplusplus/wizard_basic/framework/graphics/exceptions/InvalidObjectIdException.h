#ifndef INVALIDOBJECTIDEXCEPTION_H
#define INVALIDOBJECTIDEXCEPTION_H

#include "GraphicsException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace graphics {
namespace exceptions {

class InvalidObjectIdException : public GraphicsException {
public:
	InvalidObjectIdException(float object_id);
};

}
}
}
}
}
#endif
