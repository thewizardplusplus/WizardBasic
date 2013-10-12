#include "GraphicsModulePrivate.h"
#include "../system/SystemModule.h"
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

float GraphicsModulePrivate::getCameraPositionX(void) const {
	return camera.getPosition().x;
}

float GraphicsModulePrivate::getCameraPositionY(void) const {
	return camera.getPosition().y;
}

float GraphicsModulePrivate::getCameraPositionZ(void) const {
	return camera.getPosition().z;
}

void GraphicsModulePrivate::setCameraPosition(float x, float y, float z) {
	camera.setPosition(x, y, z);
}

float GraphicsModulePrivate::getCameraRotationX(void) const {
	return camera.getRotation().x;
}

float GraphicsModulePrivate::getCameraRotationY(void) const {
	return camera.getRotation().y;
}

float GraphicsModulePrivate::getCameraRotationZ(void) const {
	return camera.getRotation().z;
}

void GraphicsModulePrivate::setCameraRotation(float x, float y, float z) {
	camera.setRotation(x, y, z);
}

void GraphicsModulePrivate::setFogMode(float fog_mode) {
	gapi->setFogMode(std::floor(fog_mode));
}

void GraphicsModulePrivate::setFogParameters(float color_r, float color_g, float
	color_b, float density, float start_depth, float end_depth)
{
	gapi->setFogParameters(FogParameters(Vector3D<float>(color_r, color_g,
		color_b), density, start_depth, end_depth));
}

float GraphicsModulePrivate::loadObject(const base::Array& filename) {
	AnimateObject* object = AnimateObject::load(filename, gapi.get(), true);
	if (object->getTrack()->getNumberOfFrames() != 0) {
		world.addAnimateObject(object);
	} else {
		world.addObject(object);
	}
	objects.push_back(object);

	return objects.size() - 1;
}

float GraphicsModulePrivate::getObjectPositionX(float object_id) const {
	AnimateObject* object = getObjectById(object_id);
	return object->getPosition().x;
}

float GraphicsModulePrivate::getObjectPositionY(float object_id) const {
	AnimateObject* object = getObjectById(object_id);
	return object->getPosition().y;
}

float GraphicsModulePrivate::getObjectPositionZ(float object_id) const {
	AnimateObject* object = getObjectById(object_id);
	return object->getPosition().z;
}

void GraphicsModulePrivate::setObjectPosition(float object_id, float x, float y,
	float z)
{
	AnimateObject* object = getObjectById(object_id);
	object->setPosition(x, y, z);
}

float GraphicsModulePrivate::getObjectRotationX(float object_id) const {
	AnimateObject* object = getObjectById(object_id);
	return object->getRotation().x;
}

float GraphicsModulePrivate::getObjectRotationY(float object_id) const {
	AnimateObject* object = getObjectById(object_id);
	return object->getRotation().y;
}

float GraphicsModulePrivate::getObjectRotationZ(float object_id) const {
	AnimateObject* object = getObjectById(object_id);
	return object->getRotation().z;
}

void GraphicsModulePrivate::setObjectRotation(float object_id, float x, float y,
	float z)
{
	AnimateObject* object = getObjectById(object_id);
	object->setRotation(x, y, z);
}

float GraphicsModulePrivate::getObjectScaleX(float object_id) const {
	AnimateObject* object = getObjectById(object_id);
	return object->getScale().x;
}

float GraphicsModulePrivate::getObjectScaleY(float object_id) const {
	AnimateObject* object = getObjectById(object_id);
	return object->getScale().y;
}

float GraphicsModulePrivate::getObjectScaleZ(float object_id) const {
	AnimateObject* object = getObjectById(object_id);
	return object->getScale().z;
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

void GraphicsModulePrivate::pauseObjectAnimation(float object_id, float pause) {
	AnimateObject* object = getObjectById(object_id);
	object->pause(std::floor(pause));
}

float GraphicsModulePrivate::isKeyPressed(float key_code) const {
	return window->isPressedKey(static_cast<KeyCode::Types>(std::floor(
		key_code)));
}

float GraphicsModulePrivate::isButtonPressed(float button_code) const {
	return window->isPressedButton(static_cast<ButtonCode::Types>(std::floor(
		button_code)));
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
