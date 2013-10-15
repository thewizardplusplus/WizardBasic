#ifndef GRAPHICSMODULE_H
#define GRAPHICSMODULE_H

#include <Array.h>
#include <memory>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace graphics {

class GraphicsModulePrivate;

class GraphicsModule {
public:
	static GraphicsModule& getInstance(void);

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
	float isKeyPressed(float key_code);
	float getButtons(void);
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
