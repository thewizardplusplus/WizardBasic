/*#include "system/SystemModule.h"
#include "graphics/GraphicsModule.h"

using namespace thewizardplusplus::wizard_basic::framework::base;
using namespace thewizardplusplus::wizard_basic::framework::system;
using namespace thewizardplusplus::wizard_basic::framework::graphics;

int main(void) {
	WIZARD_BASIC_STRING(filename, "test.ao");
	float object = GraphicsModule::getInstance().loadObject(filename);
	GraphicsModule::getInstance().setObjectPosition(object, 0.0f, 2.5f, 0.0f);
	GraphicsModule::getInstance().setObjectRotation(object, 90.0f, 0.0f, 0.0f);
	GraphicsModule::getInstance().playObjectAnimation(object, 0, 100, 1);

	while (!GraphicsModule::getInstance().isKeyPressed(1.0f)) {
		GraphicsModule::getInstance().update();
	}
}*/

#include "sound/SoundModule.h"
#include <Maths.h>
#include <cmath>
#include <iostream>

using namespace thewizardplusplus::wizard_basic::framework::base;
using namespace thewizardplusplus::wizard_basic::framework::sound;
using namespace thewizardplusplus::anna::maths;

static const bool  USE_LISTENER = true;
static const float RADIUS =       2.0f;
static const float SPEED =        1e-3;

int main(void) {
	if (USE_LISTENER) {
		SoundModule::getInstance().setListenerPosition(0.0f, RADIUS, 0.0f);
	}

	WIZARD_BASIC_STRING(wind_filename, "wind.wav");
	float wind = SoundModule::getInstance().loadSound(wind_filename);
	SoundModule::getInstance().playSound(wind, 1);

	WIZARD_BASIC_STRING(fire_filename, "fire.wav");
	float fire = SoundModule::getInstance().loadSound(fire_filename);
	SoundModule::getInstance().playSound(fire, 1);

	float time = 0.0f;
	while (true) {
		float x = RADIUS * std::cos(SPEED * time);
		float y = RADIUS * std::sin(SPEED * time);
		if (!USE_LISTENER) {
			SoundModule::getInstance().setSoundPosition(fire, x, y, 0.0f);
			std::cout << time << ": (" << x << "; " << y << ")" << std::endl <<
				std::flush;
		} else {
			float angle = Maths::toDegrees(SPEED * time);
			SoundModule::getInstance().setListenerRotation(0.0f, 0.0f, angle);
			std::cout << time << ": " << angle << std::endl << std::flush;
		}

		time++;
	}
}
