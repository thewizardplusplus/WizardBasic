#include "GraphicsModule.h"
#include "GraphicsModulePrivate.h"

using namespace thewizardplusplus::wizard_basic::framework::graphics;

GraphicsModule& GraphicsModule::getInstance(void) {
	static GraphicsModule module;
	return module;
}

float GraphicsModule::getCameraPositionX(void) const {
	return private_realization->getCameraPositionX();
}

float GraphicsModule::getCameraPositionY(void) const {
	return private_realization->getCameraPositionY();
}

float GraphicsModule::getCameraPositionZ(void) const {
	return private_realization->getCameraPositionZ();
}

void GraphicsModule::setCameraPosition(float x, float y, float z) {
	private_realization->setCameraPosition(x, y, z);
}

float GraphicsModule::getCameraRotationX(void) const {
	return private_realization->getCameraRotationX();
}

float GraphicsModule::getCameraRotationY(void) const {
	return private_realization->getCameraRotationY();
}

float GraphicsModule::getCameraRotationZ(void) const {
	return private_realization->getCameraRotationZ();
}

void GraphicsModule::setCameraRotation(float x, float y, float z) {
	private_realization->setCameraRotation(x, y, z);
}

void GraphicsModule::setFogMode(float fog_mode) {
	private_realization->setFogMode(fog_mode);
}

void GraphicsModule::setFogParameters(float color_r, float color_g, float
	color_b, float density, float start_depth, float end_depth)
{
	private_realization->setFogParameters(color_r, color_g, color_b, density,
		start_depth, end_depth);
}

float GraphicsModule::loadObject(const base::Array& filename) {
	return private_realization->loadObject(filename);
}

float GraphicsModule::getObjectPositionX(float object_id) const {
	return private_realization->getObjectPositionX(object_id);
}

float GraphicsModule::getObjectPositionY(float object_id) const {
	return private_realization->getObjectPositionY(object_id);
}

float GraphicsModule::getObjectPositionZ(float object_id) const {
	return private_realization->getObjectPositionZ(object_id);
}

void GraphicsModule::setObjectPosition(float object_id, float x, float y,
	float z)
{
	private_realization->setObjectPosition(object_id, x, y, z);
}

float GraphicsModule::getObjectRotationX(float object_id) const {
	return private_realization->getObjectRotationX(object_id);
}

float GraphicsModule::getObjectRotationY(float object_id) const {
	return private_realization->getObjectRotationY(object_id);
}

float GraphicsModule::getObjectRotationZ(float object_id) const {
	return private_realization->getObjectRotationZ(object_id);
}

void GraphicsModule::setObjectRotation(float object_id, float x, float y,
	float z)
{
	private_realization->setObjectRotation(object_id, x, y, z);
}

float GraphicsModule::getObjectScaleX(float object_id) const {
	return private_realization->getObjectScaleX(object_id);
}

float GraphicsModule::getObjectScaleY(float object_id) const {
	return private_realization->getObjectScaleY(object_id);
}

float GraphicsModule::getObjectScaleZ(float object_id) const {
	return private_realization->getObjectScaleZ(object_id);
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

void GraphicsModule::pauseObjectAnimation(float object_id, float pause) {
	private_realization->pauseObjectAnimation(object_id, pause);
}

float GraphicsModule::isKeyPressed(float key_code) {
	return private_realization->isKeyPressed(key_code);
}

float GraphicsModule::isButtonPressed(float button_code) {
	return private_realization->isButtonPressed(button_code);
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
