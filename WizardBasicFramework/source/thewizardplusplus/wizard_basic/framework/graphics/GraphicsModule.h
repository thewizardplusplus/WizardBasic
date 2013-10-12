#ifndef GRAPHICSMODULE_H
#define GRAPHICSMODULE_H

#include "../base/Array.h"
#include <memory>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace graphics {

class GraphicsModulePrivate;

class GraphicsModule {
public:
	static GraphicsModule& getInstance(void);

	float getCameraPositionX(void) const;
	float getCameraPositionY(void) const;
	float getCameraPositionZ(void) const;
	void setCameraPosition(float x, float y, float z);
	float getCameraRotationX(void) const;
	float getCameraRotationY(void) const;
	float getCameraRotationZ(void) const;
	void setCameraRotation(float x, float y, float z);
	void setFogMode(float fog_mode);
	void setFogParameters(float color_r, float color_g, float color_b, float
		density, float start_depth, float end_depth);
	float loadObject(const base::Array& filename);
	float getObjectPositionX(float object_id) const;
	float getObjectPositionY(float object_id) const;
	float getObjectPositionZ(float object_id) const;
	void setObjectPosition(float object_id, float x, float y, float z);
	float getObjectRotationX(float object_id) const;
	float getObjectRotationY(float object_id) const;
	float getObjectRotationZ(float object_id) const;
	void setObjectRotation(float object_id, float x, float y, float z);
	float getObjectScaleX(float object_id) const;
	float getObjectScaleY(float object_id) const;
	float getObjectScaleZ(float object_id) const;
	void setObjectScale(float object_id, float x, float y, float z);
	void playObjectAnimation(float object_id, float start_frame, float
		end_frame, float loop);
	void pauseObjectAnimation(float object_id, float pause);
	float isKeyPressed(float key_code);
	float isButtonPressed(float button_code);
	float getPointerPositionX(void) const;
	float getPointerPositionY(void) const;
	void setPointerPosition(float x, float y);
	void update(void);

private:
	std::auto_ptr<GraphicsModulePrivate> private_realization;

	GraphicsModule(void);
	GraphicsModule(const GraphicsModule& sample);
	GraphicsModule& operator=(const GraphicsModule& sample);
};

}
}
}
}
#endif
