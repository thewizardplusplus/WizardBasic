#include "Graphics.h"
#include <boost/shared_ptr.hpp>
#include <irrlicht.h>

using namespace thewizardplusplus::wizard_basic::framework::graphics;
using namespace boost;
using namespace irr;

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace graphics {

static boost::shared_ptr<Graphics> graphics_module;

void Initialize(void) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module.reset(new Graphics());
}

float GetCameraPositionX(void) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getCameraPosition().X;
}

float GetCameraPositionY(void) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getCameraPosition().Y;
}

float GetCameraPositionZ(void) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getCameraPosition().Z;
}

void SetCameraPosition(float x, float y, float z) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module->setCameraPosition(core::vector3df(x, y, z));
}

float GetCameraRotationX(void) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getCameraRotation().X;
}

float GetCameraRotationY(void) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getCameraRotation().Y;
}

float GetCameraRotationZ(void) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getCameraRotation().Z;
}

void SetCameraRotation(float x, float y, float z) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module->setCameraRotation(core::vector3df(x, y, z));
}

size_t LoadObject(const std::string& filename) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->loadObject(filename);
}

float GetObjectPositionX(size_t object_id) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getObjectPosition(object_id).X;
}

float GetObjectPositionY(size_t object_id) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getObjectPosition(object_id).Y;
}

float GetObjectPositionZ(size_t object_id) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getObjectPosition(object_id).Z;
}

void SetObjectPosition(size_t object_id, float x, float y, float z) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module->setObjectPosition(object_id, core::vector3df(x, y, z));
}

float GetObjectRotationX(size_t object_id) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getObjectRotation(object_id).X;
}

float GetObjectRotationY(size_t object_id) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getObjectRotation(object_id).Y;
}

float GetObjectRotationZ(size_t object_id) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getObjectRotation(object_id).Z;
}

void SetObjectRotation(size_t object_id, float x, float y, float z) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module->setObjectRotation(object_id, core::vector3df(x, y, z));
}

float GetObjectScaleX(size_t object_id) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getObjectScale(object_id).X;
}

float GetObjectScaleY(size_t object_id) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getObjectScale(object_id).Y;
}

float GetObjectScaleZ(size_t object_id) {
	if (graphics_module) {
		throw 1;
	}

	return graphics_module->getObjectScale(object_id).Z;
}

void SetObjectScale(size_t object_id, float x, float y, float z) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module->setObjectScale(object_id, core::vector3df(x, y, z));
}

bool IsKeyPressed(irr::EKEY_CODE key_code) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module->isKeyPressed(key_code);
}

bool IsButtonPressed(MouseButton::Types button_code) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module->isButtonPressed(button_code);
}

float GetPointerPositionX(void) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module->getPointerPosition().X;
}

float GetPointerPositionY(void) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module->getPointerPosition().Y;
}

void SetPointerPosition(float x, float y) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module->setPointerPosition(core::vector2di(x, y));
}

void Update(void) {
	if (graphics_module) {
		throw 1;
	}

	graphics_module->update();
}

}
}
}
}
