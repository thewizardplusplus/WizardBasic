#include "GraphicsModulePrivate.h"
#include "../system/SystemModule.h"
#include "../utils/os.h"
#include "Mesh.h"
#include "exceptions/InvalidObjectIdException.h"
#include <OpenGlGraphicApi.h>
#include <cmath>
#include <algorithm>

using namespace thewizardplusplus::wizard_basic::framework::graphics;
using namespace thewizardplusplus::anna::graphics;
using namespace thewizardplusplus::wizard_basic::framework::system;
using namespace thewizardplusplus::anna::maths;
using namespace thewizardplusplus::wizard_basic::framework::graphics::
	exceptions;

GraphicsModulePrivate::GraphicsModulePrivate(void) :
	window(NULL),
	last_time(0)
{
	gapi.reset(GraphicApi::create<OpenGlGraphicApi>());
	window = gapi->getWindow();
	world.setCamera(&camera);
	last_time = SystemModule::getInstance().getTimeFromStartInS();
}

float GraphicsModulePrivate::getScreenWidth(void) {
	return window->getSize().x;
}

float GraphicsModulePrivate::getScreenHeight(void) {
	return window->getSize().y;
}

void GraphicsModulePrivate::setCameraPosition(float x, float y, float z) {
	camera.setPosition(x, y, z);
}

void GraphicsModulePrivate::setCameraRotation(float x, float y, float z) {
	camera.setRotation(x, y, z);
}

void GraphicsModulePrivate::setFogMode(float fog_mode) {
	gapi->setFogMode(std::floor(fog_mode));
}

void GraphicsModulePrivate::setFogColor(float r, float g, float b) {
	FogParameters parameters = gapi->getFogParameters();
	parameters.color = Vector3D<float>(r, g, b) / 255.0f;
	gapi->setFogParameters(parameters);
}

void GraphicsModulePrivate::setFogDepth(float end_depth) {
	FogParameters parameters = gapi->getFogParameters();
	parameters.end_depth = end_depth;
	gapi->setFogParameters(parameters);
}

float GraphicsModulePrivate::loadObject(const base::Array& filename) {
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

	AnimateObject* object = AnimateObject::load(string_filename, gapi.get(),
		true);

	size_t number_of_meshes = object->getNumberOfMeshes();
	for (size_t i = 0; i < number_of_meshes; i++) {
		Mesh* mesh = object->getMesh(i);
		if (mesh->getMaterial().transparent_type == TransparentType::BLENDING) {
			mesh->getMaterial().transparent_type = TransparentType::ALPHA_TEST;
		}
	}

	if (object->getTrack() != NULL && object->getTrack()->getNumberOfFrames() !=
		0)
	{
		world.addAnimateObject(object);
	} else {
		world.addObject(object);
	}
	objects.push_back(object);

	return objects.size() - 1;
}

void GraphicsModulePrivate::setObjectPosition(float object_id, float x, float y,
	float z)
{
	AnimateObject* object = getObjectById(object_id);
	object->setPosition(x, y, z);
}

void GraphicsModulePrivate::setObjectRotation(float object_id, float x, float y,
	float z)
{
	AnimateObject* object = getObjectById(object_id);
	object->setRotation(x, y, z);
}

void GraphicsModulePrivate::setObjectScale(float object_id, float x, float y,
	float z)
{
	AnimateObject* object = getObjectById(object_id);
	object->setScale(x, y, z);
}

void GraphicsModulePrivate::playObjectAnimation(float object_id, float
	start_frame, float end_frame, float loop)
{
	AnimateObject* object = getObjectById(object_id);
	object->play(std::floor(loop), std::floor(start_frame), std::floor(
		end_frame));
}

void GraphicsModulePrivate::pauseObjectAnimation(float object_id) {
	AnimateObject* object = getObjectById(object_id);
	object->pause(false);
}

float GraphicsModulePrivate::isKeyPressed(float key_code) const {
	return window->isPressedKey(static_cast<KeyCode::Types>(std::floor(
		key_code)));
}

float GraphicsModulePrivate::getButtons(void) const {
	return window->isPressedButton(ButtonCode::BUTTON_MIDDLE) << 2 | window->
		isPressedButton(ButtonCode::BUTTON_RIGHT) << 1 | window->
		isPressedButton(ButtonCode::BUTTON_LEFT);
}

float GraphicsModulePrivate::getPointerPositionX(void) const {
	return window->getPointerPosition().x;
}

float GraphicsModulePrivate::getPointerPositionY(void) const {
	return window->getPointerPosition().y;
}

void GraphicsModulePrivate::setPointerPosition(float x, float y) {
	window->setPointerPosition(x, y);
}

void GraphicsModulePrivate::update(void) {
	float current_time = SystemModule::getInstance().getTimeFromStartInS();
	world.update(1000.0f * (current_time - last_time));
	last_time = current_time;

	gapi->clear();
	gapi->drawWorld(&world);
	window->update();
}

AnimateObject* GraphicsModulePrivate::getObjectById(float object_id) const {
	if (object_id < 0 || object_id >= objects.size()) {
		throw InvalidObjectIdException(object_id);
	}

	ObjectList::const_iterator iterator = objects.begin();
	std::advance(iterator, std::floor(object_id));

	return *iterator;
}
