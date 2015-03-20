#ifndef SOUNDMODULEPRIVATE_H
#define SOUNDMODULEPRIVATE_H

#include "../base/Array.h"
#include <SoundManager.h>
#include <Vector3D.h>
#include <memory>
#include <list>

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace sound {

class SoundModulePrivate {
public:
	SoundModulePrivate(void);
	void setListenerPosition(float x, float y, float z);
	void setListenerRotation(float x, float y, float z);
	float loadSound(const base::Array& filename);
	void setSoundPosition(float sound_id, float x, float y, float z);
	void playSound(float sound_id, float loop);
	void stopSound(float sound_id);

private:
	typedef std::list<anna::sound::Sound*> SoundList;

	std::auto_ptr<anna::sound::SoundManager> sound_manager;
	SoundList                                sounds;

	anna::sound::Sound* getSoundById(float sound_id) const;
	anna::maths::Vector3D<float> rotateVector(const anna::maths::Vector3D<
		float>& vector, const anna::maths::Vector3D<float>& angles);
};

}
}
}
}
#endif
