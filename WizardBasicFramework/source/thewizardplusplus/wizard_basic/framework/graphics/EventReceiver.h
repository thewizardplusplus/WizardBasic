#ifndef EVENTRECEIVER_H
#define EVENTRECEIVER_H

#include "MouseButton.h"
#include <irrlicht.h>
#include <set>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace graphics {

class EventReceiver : public irr::IEventReceiver {
public:
	EventReceiver(void);
	virtual bool OnEvent(const irr::SEvent& event);
	bool isKeyPressed(irr::EKEY_CODE key_code) const;
	bool isButtonPressed(MouseButton::Types button) const;
	irr::core::vector2di getPointerPosition(void) const;
	void setPointerPosition(const irr::core::vector2di& pointer_position);

private:
	typedef std::set<irr::EKEY_CODE> KeySet;

	KeySet               keys;
	unsigned char        buttons;
	irr::core::vector2di pointer_position;
};

}
}
}
}
#endif
