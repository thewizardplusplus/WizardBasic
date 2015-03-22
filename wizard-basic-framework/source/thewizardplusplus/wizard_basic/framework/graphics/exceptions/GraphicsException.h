#ifndef GRAPHICSEXCEPTION_H
#define GRAPHICSEXCEPTION_H

#include "../../exceptions/WizardBasicFrameworkException.h"

namespace thewizardplusplus {
namespace wizard_basic_2 {
namespace framework {
namespace graphics {
namespace exceptions {

class GraphicsException : public framework::exceptions::
	WizardBasicFrameworkException
{
public:
	GraphicsException(const std::string& message);
};

}
}
}
}
}
#endif
