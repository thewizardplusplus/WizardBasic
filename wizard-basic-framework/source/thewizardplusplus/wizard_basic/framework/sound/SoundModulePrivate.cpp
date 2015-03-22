#include "SoundModulePrivate.h"
#include "../utils/os.h"
#include "exceptions/InvalidSoundIdException.h"
#include <AudioDevice.h>
#include <Sound.h>
#include <Listener.h>
#include <Source.h>
#include <cmath>
#include <algorithm>

using namespace thewizardplusplus::wizard_basic_2::framework::sound;
using namespace thewizardplusplus::anna::sound;
using namespace thewizardplusplus::anna::maths;
using namespace thewizardplusplus::wizard_basic_2::framework::sound::exceptions;

SoundModulePrivate::SoundModulePrivate(void) {
	sound_manager.reset(new SoundManager());
}

void SoundModulePrivate::setListenerPosition(float x, float y, float z) {
	sound_manager->getAudioDevice()->getListener()->setPosition(Vector3D<float>(
		x, y, z));
}

void SoundModulePrivate::setListenerRotation(float x, float y, float z) {
	Vector3D<float> rotate_angles(x, y, z);

	Vector3D<float> forward_direction(0.0f, 1.0f, 0.0f);
	forward_direction = rotateVector(forward_direction, rotate_angles);

	Vector3D<float> up_direction(0.0f, 0.0f, 1.0f);
	up_direction = rotateVector(up_direction, rotate_angles);

	sound_manager->getAudioDevice()->getListener()->setForwardDirection(
		forward_direction);
	sound_manager->getAudioDevice()->getListener()->setUpDirection(
		up_direction);
}

float SoundModulePrivate::loadSound(const base::Array& filename) {
	std::string string_filename = filename;
	#ifdef OS_LINUX
	char wrong_separator = '\\';
	char right_separator = '/';
	#elif defined(OS_WINDOWS)
	char wrong_separator = '/';
	char right_separator = '\\';
	#endif
	std::replace(string_filename.begin(), string_filename.end(),
		wrong_separator, right_separator);

	Sound* sound = sound_manager->createSound(string_filename);
	sounds.push_back(sound);

	return sounds.size() - 1;
}

void SoundModulePrivate::setSoundPosition(float sound_id, float x, float y,
	float z)
{
	Sound* sound = getSoundById(sound_id);
	sound->getSource()->setPosition(Vector3D<float>(x, y, z));
}

void SoundModulePrivate::playSound(float sound_id, float loop) {
	Sound* sound = getSoundById(sound_id);
	sound->getSource()->setLooping(std::floor(loop));
	sound->getSource()->play();
}

void SoundModulePrivate::stopSound(float sound_id) {
	Sound* sound = getSoundById(sound_id);
	sound->getSource()->stop();
}

Sound* SoundModulePrivate::getSoundById(float sound_id) const {
	if (sound_id < 0 || sound_id >= sounds.size()) {
		throw InvalidSoundIdException(sound_id);
	}

	SoundList::const_iterator iterator = sounds.begin();
	std::advance(iterator, std::floor(sound_id));

	return *iterator;
}

Vector3D<float> SoundModulePrivate::rotateVector(const Vector3D<float>& vector,
	const Vector3D<float>& angles)
{
	Vector3D<float> vector_rotated_at_x;
	vector_rotated_at_x.x = vector.x;
	vector_rotated_at_x.y = vector.y * std::cos(Maths::toRadians(angles.x)) +
		vector.z * std::sin(Maths::toRadians(angles.x));
	vector_rotated_at_x.z = -vector.y * std::sin(Maths::toRadians(angles.x)) +
		vector.z * std::cos(Maths::toRadians(angles.x));

	Vector3D<float> vector_rotated_at_y;
	vector_rotated_at_y.x = vector_rotated_at_x.x * std::cos(Maths::toRadians(
		angles.y)) + vector_rotated_at_x.z * std::sin(Maths::toRadians(angles.
		y));
	vector_rotated_at_y.y = vector_rotated_at_x.y;
	vector_rotated_at_y.z = -vector_rotated_at_x.x * std::sin(Maths::toRadians(
		angles.y)) + vector_rotated_at_x.z * std::cos(Maths::toRadians(angles.
		y));

	Vector3D<float> vector_rotated_at_z;
	vector_rotated_at_z.x = vector_rotated_at_y.x * std::cos(Maths::toRadians(
		angles.z)) + vector_rotated_at_y.y * std::sin(Maths::toRadians(angles.
		z));
	vector_rotated_at_z.y = -vector_rotated_at_y.x * std::sin(Maths::toRadians(
		angles.z)) + vector_rotated_at_y.y * std::cos(Maths::toRadians(angles.
		z));
	vector_rotated_at_z.z = vector_rotated_at_y.z;

	return vector_rotated_at_z;
}
