#include "GraphicsModulePrivate.h"

using namespace thewizardplusplus::wizard_basic::framework::graphics;

GraphicsModulePrivate::GraphicsModulePrivate(void) {}

float GraphicsModulePrivate::getCameraPositionX(void) const {}

float GraphicsModulePrivate::getCameraPositionY(void) const {}

float GraphicsModulePrivate::getCameraPositionZ(void) const {}

void GraphicsModulePrivate::setCameraPosition(float x, float y, float z) {}

float GraphicsModulePrivate::getCameraRotationX(void) const {}

float GraphicsModulePrivate::getCameraRotationY(void) const {}

float GraphicsModulePrivate::getCameraRotationZ(void) const {}

void GraphicsModulePrivate::setCameraRotation(float x, float y, float z) {}

void GraphicsModulePrivate::setFogMode(float fog_mode) {}

void GraphicsModulePrivate::setFogParameters(float color_r, float color_g, float
	color_b, float density, float start_depth, float end_depth)
{}

float GraphicsModulePrivate::loadObject(const base::Array& filename) {}

float GraphicsModulePrivate::getObjectPositionX(float object_id) const {}

float GraphicsModulePrivate::getObjectPositionY(float object_id) const {}

float GraphicsModulePrivate::getObjectPositionZ(float object_id) const {}

void GraphicsModulePrivate::setObjectPosition(float object_id, float x, float y,
	float z)
{}

float GraphicsModulePrivate::getObjectRotationX(float object_id) const {}

float GraphicsModulePrivate::getObjectRotationY(float object_id) const {}

float GraphicsModulePrivate::getObjectRotationZ(float object_id) const {}

void GraphicsModulePrivate::setObjectRotation(float object_id, float x, float y,
	float z)
{}

float GraphicsModulePrivate::getObjectScaleX(float object_id) const {}

float GraphicsModulePrivate::getObjectScaleY(float object_id) const {}

float GraphicsModulePrivate::getObjectScaleZ(float object_id) const {}

void GraphicsModulePrivate::setObjectScale(float object_id, float x, float y,
	float z)
{}

float GraphicsModulePrivate::isKeyPressed(float key_code) {}

float GraphicsModulePrivate::isButtonPressed(float button_code) {}

float GraphicsModulePrivate::getPointerPositionX(void) const {}

float GraphicsModulePrivate::getPointerPositionY(void) const {}

void GraphicsModulePrivate::setPointerPosition(float x, float y) {}

void GraphicsModulePrivate::update(void) {}
