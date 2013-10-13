#ifndef OPENOBJECTFILEEXCEPTION_H
#define OPENOBJECTFILEEXCEPTION_H

#include "GraphicsException.h"

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace graphics {
namespace exceptions {

class OpenObjectFileException : public GraphicsException {
public:
	OpenObjectFileException(const std::string& object_filename);
};

}
}
}
}
}
#endif
