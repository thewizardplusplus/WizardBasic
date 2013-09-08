#ifndef GRAPHICS_FUNCTIONS_H
#define GRAPHICS_FUNCTIONS_H

namespace thewizardplusplus {
namespace wizard_basic {
namespace framework {
namespace graphics {

void Initialize(void);
float GetCameraPositionX(void);
float GetCameraPositionY(void);
float GetCameraPositionZ(void);
void SetCameraPosition(float x, float y, float z);
float GetCameraRotationX(void);
float GetCameraRotationY(void);
float GetCameraRotationZ(void);
void SetCameraRotation(float x, float y, float z);
size_t LoadObject(const std::string& filename);
float GetObjectPositionX(size_t object_id);
float GetObjectPositionY(size_t object_id);
float GetObjectPositionZ(size_t object_id);
void SetObjectPosition(size_t object_id, float x, float y, float z);
float GetObjectRotationX(size_t object_id);
float GetObjectRotationY(size_t object_id);
float GetObjectRotationZ(size_t object_id);
void SetObjectRotation(size_t object_id, float x, float y, float z);
float GetObjectScaleX(size_t object_id);
float GetObjectScaleY(size_t object_id);
float GetObjectScaleZ(size_t object_id);
void SetObjectScale(size_t object_id, float x, float y, float z);
bool IsKeyPressed(irr::EKEY_CODE key_code);
bool IsButtonPressed(MouseButton::Types button_code);
float GetPointerPositionX(void);
float GetPointerPositionY(void);
void SetPointerPosition(float x, float y);
void Update(void);

}
}
}
}
#endif
