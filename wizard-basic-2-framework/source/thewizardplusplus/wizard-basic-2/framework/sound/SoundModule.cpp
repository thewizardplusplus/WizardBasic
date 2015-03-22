#include "SoundModule.h"
#include "SoundModulePrivate.h"

using namespace thewizardplusplus::wizard_basic_2::framework::sound;

SoundModule& SoundModule::getInstance(void) {
	static SoundModule module;
	return module;
}

void SoundModule::setListenerPosition(float x, float y, float z) {
	private_realization->setListenerPosition(x, y, z);
}

void SoundModule::setListenerRotation(float x, float y, float z) {
	private_realization->setListenerRotation(x, y, z);
}

float SoundModule::loadSound(const base::Array& filename) {
	return private_realization->loadSound(filename);
}

void SoundModule::setSoundPosition(float sound_id, float x, float y, float z) {
	private_realization->setSoundPosition(sound_id, x, y, z);
}

void SoundModule::playSound(float sound_id, float loop) {
	private_realization->playSound(sound_id, loop);
}

void SoundModule::stopSound(float sound_id) {
	private_realization->stopSound(sound_id);
}

SoundModule::SoundModule(void) {
	private_realization.reset(new SoundModulePrivate());
}
