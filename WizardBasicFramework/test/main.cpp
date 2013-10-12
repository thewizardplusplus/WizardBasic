#include <SystemModule.h>
#include <GraphicsModule.h>

using namespace thewizardplusplus::wizard_basic::framework::system;
using namespace thewizardplusplus::wizard_basic::framework::graphics;
using namespace thewizardplusplus::wizard_basic::framework::base;

int main(void) {
	WIZARD_BASIC_STRING(filename, "test.ao");
	float object = GraphicsModule::getInstance().loadObject(filename);
	GraphicsModule::getInstance().setObjectPosition(object, 0.0f, 2.5f, 0.0f);
	GraphicsModule::getInstance().setObjectRotation(object, 0.0f, 0.0f, 90.0f);
	GraphicsModule::getInstance().playObjectAnimation(object, 1, 100, true);

	while (!GraphicsModule::getInstance().isKeyPressed(1.0f)) {
		GraphicsModule::getInstance().update();
	}
}
