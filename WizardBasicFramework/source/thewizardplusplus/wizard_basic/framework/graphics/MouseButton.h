#ifndef MOUSEBUTTON_H
#define MOUSEBUTTON_H

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace graphics {

class MouseButton {
public:
	enum Types {
		NONE,
		LEFT =   1 << 0,
		MIDDLE = 1 << 1,
		RIGHT =  1 << 2
	};
};

}
}
}
}
#endif
