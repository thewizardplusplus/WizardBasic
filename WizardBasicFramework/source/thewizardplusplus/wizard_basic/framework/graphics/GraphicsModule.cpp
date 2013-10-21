#include "GraphicsModule.h"
#include "GraphicsModulePrivate.h"

using namespace thewizardplusplus::wizard_basic::framework::graphics;

GraphicsModule& GraphicsModule::getInstance(void) {
	static GraphicsModule module;
	return module;
}

float GraphicsModule::getScreenWidth(void) {
	return private_realization->getScreenWidth();
}

float GraphicsModule::getScreenHeight(void) {
	return private_realization->getScreenHeight();
}

void GraphicsModule::setCameraPosition(float x, float y, float z) {
	private_realization->setCameraPosition(x, y, z);
}

void GraphicsModule::setCameraRotation(float x, float y, float z) {
	private_realization->setCameraRotation(x, y, z);
}

void GraphicsModule::setAmbientLightMode(float ambient_light_mode) {
	private_realization->setAmbientLightMode(ambient_light_mode);
}

void GraphicsModule::setAmbientLightColor(float r, float g, float b) {
	private_realization->setAmbientLightColor(r, g, b);
}

void GraphicsModule::setFogMode(float fog_mode) {
	private_realization->setFogMode(fog_mode);
}

void GraphicsModule::setFogColor(float r, float g, float b) {
	private_realization->setFogColor(r, g, b);
}

void GraphicsModule::setFogDepth(float end_depth) {
	private_realization->setFogDepth(end_depth);
}

float GraphicsModule::loadObject(const base::Array& filename) {
	return private_realization->loadObject(filename);
}

void GraphicsModule::setObjectPosition(float object_id, float x, float y,
	float z)
{
	private_realization->setObjectPosition(object_id, x, y, z);
}

void GraphicsModule::setObjectRotation(float object_id, float x, float y,
	float z)
{
	private_realization->setObjectRotation(object_id, x, y, z);
}

void GraphicsModule::setObjectScale(float object_id, float x, float y,
	float z)
{
	private_realization->setObjectScale(object_id, x, y, z);
}

void GraphicsModule::playObjectAnimation(float object_id, float start_frame,
	float end_frame, float loop)
{
	private_realization->playObjectAnimation(object_id, start_frame, end_frame,
		loop);
}

void GraphicsModule::pauseObjectAnimation(float object_id) {
	private_realization->pauseObjectAnimation(object_id);
}

float GraphicsModule::isKeyPressed(float key_code) {
	return private_realization->isKeyPressed(key_code);
}

float GraphicsModule::getButtons(void) {
	return private_realization->getButtons();
}

float GraphicsModule::getPointerPositionX(void) const {
	return private_realization->getPointerPositionX();
}

float GraphicsModule::getPointerPositionY(void) const {
	return private_realization->getPointerPositionY();
}

void GraphicsModule::setPointerPosition(float x, float y) {
	private_realization->setPointerPosition(x, y);
}

void GraphicsModule::update(void) {
	private_realization->update();
}

GraphicsModule::GraphicsModule(void) {
	private_realization.reset(new GraphicsModulePrivate());
}
