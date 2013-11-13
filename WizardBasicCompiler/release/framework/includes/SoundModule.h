#ifndef SOUNDMODULE_H
#define SOUNDMODULE_H

#include <Array.h>
#include <memory>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace sound {

class SoundModulePrivate;

class SoundModule {
public:
	static SoundModule& getInstance(void);

	void setListenerPosition(float x, float y, float z);
	void setListenerRotation(float x, float y, float z);
	float loadSound(const base::Array& filename);
	void setSoundPosition(float sound_id, float x, float y, float z);
	void playSound(float sound_id, float loop);
	void stopSound(float sound_id);

private:
	std::auto_ptr<SoundModulePrivate> private_realization;

	SoundModule(void);
	SoundModule(const SoundModule& sample);
	SoundModule& operator=(const SoundModule& sample);
};

}
}
}
}
#endif
