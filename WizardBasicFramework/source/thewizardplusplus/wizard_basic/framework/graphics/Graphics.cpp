#include "Graphics.h"
#include "../system/os.h"
#ifdef OS_LINUX
#include "exceptions/FailureToOpenConnectionToXServer.h"
#include <X11/Xlib.h>
#elif defined(OS_WINDOWS)
#include <windows.h>
#endif
#include <cstdlib>

using namespace thewizardplusplus::wizard_basic::framework::graphics;
using namespace irr;

Graphics::Graphics(void) :
	event_receiver(NULL),
	irrlicht_device(NULL),
	video_driver(NULL),
	scene_manager(NULL),
	camera_node(NULL)
{
	event_receiver = new EventReceiver();

	SIrrlichtCreationParameters parameters;
	parameters.Bits =          32;
	parameters.DriverType =    video::EDT_OPENGL;
	parameters.EventReceiver = event_receiver;
	#ifdef DEBUG
	parameters.Fullscreen =    false;
	#else
	parameters.Fullscreen =    true;
	#endif
	parameters.WindowSize =    getScreenSize();
	irrlicht_device = createDeviceEx(parameters);
	if (irrlicht_device == NULL) {
		//throw FailureCreateIrrlichtDevice();
		throw 1;
	}

	video_driver = irrlicht_device->getVideoDriver();
	video_driver->setTextureCreationFlag(video::ETCF_ALWAYS_32_BIT, true);

	scene_manager = irrlicht_device->getSceneManager();

	camera_node = scene_manager->addCameraSceneNode();
	if (camera_node == NULL) {
		//throw FailureCreateCamera();
		throw 2;
	}
}

Graphics::~Graphics(void) {
	irrlicht_device->drop();
}

irr::core::vector3df Graphics::getCameraPosition(void) const {
	return camera_node->getPosition();
}

void Graphics::setCameraPosition(const irr::core::vector3df& position) {
	camera_node->setPosition(position);
}

irr::core::vector3df Graphics::getCameraRotation(void) const {
	return camera_node->getRotation();
}

void Graphics::setCameraRotation(const irr::core::vector3df& rotation) {
	camera_node->setRotation(rotation);
}

size_t Graphics::loadObject(const std::string& filename) {
	scene::IMesh* mesh = scene_manager->getMesh(filename.c_str());
	if (mesh == NULL) {
		//throw FailureLoadMesh(filename);
		throw 3;
	}

	scene::IMeshSceneNode* mesh_node = scene_manager->addMeshSceneNode(mesh);
	if (mesh_node == NULL) {
		//throw FailureCreateMeshObject(filename);
		throw 4;
	}
	mesh_node->setMaterialFlag(video::EMF_LIGHTING, false);

	mesh_nodes.push_back(mesh_node);
	return mesh_nodes.size() - 1;
}

irr::core::vector3df Graphics::getObjectPosition(size_t object_id) const {
	return getObject(object_id)->getPosition();
}

void Graphics::setObjectPosition(size_t object_id, const core::vector3df&
	position)
{
	getObject(object_id)->setPosition(position);
}

irr::core::vector3df Graphics::getObjectRotation(size_t object_id) const {
	return getObject(object_id)->getRotation();
}

void Graphics::setObjectRotation(size_t object_id, const core::vector3df&
	rotation)
{
	getObject(object_id)->setRotation(rotation);
}

irr::core::vector3df Graphics::getObjectScale(size_t object_id) const {
	return getObject(object_id)->getScale();
}

void Graphics::setObjectScale(size_t object_id, const core::vector3df& scale) {
	getObject(object_id)->setScale(scale);
}

bool Graphics::isKeyPressed(EKEY_CODE key_code) {
	return event_receiver->isKeyPressed(key_code);
}

bool Graphics::isButtonPressed(MouseButton::Types button_code) {
	return event_receiver->isButtonPressed(button_code);
}

core::vector2di Graphics::getPointerPosition(void) const {
	return event_receiver->getPointerPosition();
}

void Graphics::setPointerPosition(const core::vector2di& position) {
	irrlicht_device->getCursorControl()->setPosition(position);
	event_receiver->setPointerPosition(position);
}

void Graphics::update(void) {
	video_driver->beginScene();
	scene_manager->drawAll();
	video_driver->endScene();

	bool result = irrlicht_device->run();
	if (!result) {
		this->~Graphics();
		std::exit(EXIT_SUCCESS);
	}
}

core::dimension2du Graphics::getScreenSize(void) const {
	core::dimension2du screen_size;
	#ifdef OS_LINUX
	Display* display = XOpenDisplay(NULL);
	if (display == NULL) {
		throw FailureToOpenConnectionToXServer();
	}
	int screen = DefaultScreen(display);
	screen_size.Width = DisplayWidth(display, screen);
	screen_size.Height = DisplayHeight(display, screen);
	#elif defined(OS_WINDOWS)
	screen_size.Width = GetSystemMetrics(SM_CXSCREEN);
	screen_size.Height = GetSystemMetrics(SM_CYSCREEN);
	#endif
	#ifdef DEBUG
	screen_size.Width /= 2;
	screen_size.Height /= 2;
	#endif
	return screen_size;
}

scene::IMeshSceneNode* Graphics::getObject(size_t object_id) const {
	if (object_id >= mesh_nodes.size()) {
		throw 1;
	}

	MeshNodeList::const_iterator i = mesh_nodes.begin();
	std::advance(i, object_id);
	return *i;
}
