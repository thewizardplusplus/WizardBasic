#include "GraphicsModulePrivate.h"
#include "../system/SystemModule.h"
#include "exceptions/OpenObjectFileException.h"
#include "exceptions/InvalidObjectIdException.h"
#include <OpenGlGraphicApi.h>
#include <cmath>

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
	parameters.color = Vector3D<float>(r, g, b);
	gapi->setFogParameters(parameters);
}

void GraphicsModulePrivate::setFogDensity(float density) {
	FogParameters parameters = gapi->getFogParameters();
	parameters.density = density;
	gapi->setFogParameters(parameters);
}

void GraphicsModulePrivate::setFogDepth(float start, float end) {
	FogParameters parameters = gapi->getFogParameters();
	parameters.start_depth = start;
	parameters.end_depth = end;
	gapi->setFogParameters(parameters);
}

float GraphicsModulePrivate::loadObject(const base::Array& filename) {
	AnimateObject* object = AnimateObject::load(filename, gapi.get(), true);
	if (object == NULL) {
		throw OpenObjectFileException(filename);
	}

	if (object->getTrack()->getNumberOfFrames() != 0) {
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
