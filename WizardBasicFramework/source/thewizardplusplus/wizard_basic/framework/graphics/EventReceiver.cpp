#include "EventReceiver.h"

using namespace thewizardplusplus::wizard_basic::framework::graphics;
using namespace irr;

EventReceiver::EventReceiver(void) :
	buttons(MouseButton::NONE)
{}

bool EventReceiver::OnEvent(const irr::SEvent& event) {
	if (event.EventType == EET_KEY_INPUT_EVENT) {
		if (event.KeyInput.PressedDown) {
			keys.insert(event.KeyInput.Key);
		} else {
			keys.erase(event.KeyInput.Key);
		}
	} else if (event.EventType == EET_MOUSE_INPUT_EVENT) {
		buttons = MouseButton::NONE;
		if (event.MouseInput.isLeftPressed()) {
			buttons |= MouseButton::LEFT;
		}
		if (event.MouseInput.isMiddlePressed()) {
			buttons |= MouseButton::MIDDLE;
		}
		if (event.MouseInput.isRightPressed()) {
			buttons |= MouseButton::RIGHT;
		}

		pointer_position = core::vector2d<int>(event.MouseInput.X, event.
			MouseInput.Y);
	}

	return true;
}

bool EventReceiver::isKeyPressed(irr::EKEY_CODE key_code) const {
	return keys.find(key_code) != keys.end();
}

bool EventReceiver::isButtonPressed(MouseButton::Types button) const {
	return buttons & button;
}

core::vector2di EventReceiver::getPointerPosition(void) const {
	return pointer_position;
}

void EventReceiver::setPointerPosition(const core::vector2di& pointer_position)
{
	this->pointer_position = pointer_position;
}
