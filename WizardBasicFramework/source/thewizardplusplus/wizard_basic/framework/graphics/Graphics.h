#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "EventReceiver.h"
#include <string>
#include <list>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace graphics {

class Graphics {
public:
	Graphics(void);
	~Graphics(void);
	irr::core::vector3df getCameraPosition(void) const;
	void setCameraPosition(const irr::core::vector3df& position);
	irr::core::vector3df getCameraRotation(void) const;
	void setCameraRotation(const irr::core::vector3df& rotation);
	size_t loadObject(const std::string& filename);
	irr::core::vector3df getObjectPosition(size_t object_id) const;
	void setObjectPosition(size_t object_id, const irr::core::vector3df&
		position);
	irr::core::vector3df getObjectRotation(size_t object_id) const;
	void setObjectRotation(size_t object_id, const irr::core::vector3df&
		rotation);
	irr::core::vector3df getObjectScale(size_t object_id) const;
	void setObjectScale(size_t object_id, const irr::core::vector3df& scale);
	bool isKeyPressed(irr::EKEY_CODE key_code);
	bool isButtonPressed(MouseButton::Types button_code);
	irr::core::vector2di getPointerPosition(void) const;
	void setPointerPosition(const irr::core::vector2di& position);
	void update(void);

private:
	typedef std::list<irr::scene::IMeshSceneNode*> MeshNodeList;

	EventReceiver*                event_receiver;
	irr::IrrlichtDevice*          irrlicht_device;
	irr::video::IVideoDriver*     video_driver;
	irr::scene::ISceneManager*    scene_manager;
	irr::scene::ICameraSceneNode* camera_node;
	MeshNodeList                  mesh_nodes;

	irr::core::dimension2du getScreenSize(void) const;
	irr::scene::IMeshSceneNode* getObject(size_t object_id) const;
};

}
}
}
}
#endif
