#ifndef GRAPHICSMODULEPRIVATE_H
#define GRAPHICSMODULEPRIVATE_H

#include "../base/Array.h"
#include <GraphicApi.h>
#include <memory>
#include <list>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace graphics {

class GraphicsModulePrivate {
public:
	GraphicsModulePrivate(void);
	void setCameraPosition(float x, float y, float z);
	void setCameraRotation(float x, float y, float z);
	void setFogMode(float fog_mode);
	void setFogColor(float r, float g, float b);
	void setFogDensity(float density);
	void setFogDepth(float start, float end);
	float loadObject(const base::Array& filename);
	void setObjectPosition(float object_id, float x, float y, float z);
	void setObjectRotation(float object_id, float x, float y, float z);
	void setObjectScale(float object_id, float x, float y, float z);
	void playObjectAnimation(float object_id, float start_frame, float
		end_frame, float loop);
	void pauseObjectAnimation(float object_id);
	float isKeyPressed(float key_code) const;
	float getButtons(void) const;
	float getPointerPositionX(void) const;
	float getPointerPositionY(void) const;
	void setPointerPosition(float x, float y);
	void update(void);

private:
	typedef std::list<anna::graphics::AnimateObject*> ObjectList;

	std::auto_ptr<anna::graphics::GraphicApi> gapi;
	anna::graphics::Window*                   window;
	anna::graphics::Camera                    camera;
	anna::graphics::World                     world;
	float                                     last_time;
	ObjectList                                objects;

	anna::graphics::AnimateObject* getObjectById(float object_id) const;
};

}
}
}
}
#endif
