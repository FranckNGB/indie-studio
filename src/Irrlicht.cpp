/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Irrlicht
*/

#include <irr/irrlicht.h>
#include <stdexcept>
#include <iostream>
#include <irr/driverChoice.h>
#include "../inc/Irrlicht.hpp"
#include "../inc/Data.hpp"
#include "../inc/Tools.hpp"
#include "../inc/Player.hpp"
#include "../inc/ISound.hpp"

Irrlicht::Irrlicht(GraphParams &params) :
	_resolution({(irr::u32)params.resolution.first, (irr::u32)params.resolution.second}),
	_verbose(params.verbose),
	_deviceReceiver(params.verbose)
{
	_device = irr::createDevice(irr::video::EDT_OPENGL, irr::core::dimension2d(_resolution.first, _resolution.second), 32, params.fullScreen, false, params.vSync, &_deviceReceiver);
	if (_device == nullptr)
		throw std::runtime_error("Couldn't find any device !");
	Tools::displayVerbose(_verbose, "Device created !");
	_device->setWindowCaption(L"Bomberman");
	_device->setResizable(false);
	_driver = _device->getVideoDriver();
	if (_driver == nullptr)
		throw std::runtime_error("Couldn't get any video driver !");
	_sceneManager = _device->getSceneManager();
	_gui = _device->getGUIEnvironment();
	_font = _gui->getFont("texture/bigfont.png");
	if (_font == nullptr)
		throw std::runtime_error("Couldn't load font !");
	_camera = _sceneManager->addCameraSceneNode(nullptr, irr::core::vector3df(100.0f, .0f, 20.0f), irr::core::vector3df(0.0f, 0.0f, 0.0f));
	_sceneManager->setAmbientLight(irr::video::SColorf(1.0,1.0,1.0,0.0));
	_gui->getSkin()->setFont(_font, irr::gui::EGDF_BUTTON);
	_gui->getSkin()->setFont(_font, irr::gui::EGDF_DEFAULT);
}

Irrlicht::~Irrlicht()
{
	_device->closeDevice();
	_device->drop();
}

void	Irrlicht::clear()
{
	_sceneBomb.clear();
	_guiElement.clear();
	_sceneElement.clear();
	_sceneManager->clear();
	_gui->clear();
	_textElement.clear();
	_sceneCube.clear();
	_camera = _sceneManager->addCameraSceneNode(nullptr, irr::core::vector3df(100.0f, .0f, 20.0f), irr::core::vector3df(0.0f, 0.0f, 0.0f));
	_sceneManager->setAmbientLight(irr::video::SColorf(1.0,1.0,1.0,0.0));
}

void	Irrlicht::display()
{
	irr::video::SColor	color(255, 0, 0, 0);

	if (_deviceReceiver.IsKeyDown(irr::KEY_ESCAPE)) {
		_device->closeDevice();
	}
	_driver->beginScene(true, true, color);
	_sceneManager->drawAll();
	_gui->drawAll();
	_driver->endScene();
}

bool	Irrlicht::isOpen() const
{
	return _device->run();
}

void	Irrlicht::getEvents(std::pair<int, std::string> &keyCode)
{
	std::string	btnName = "";

	for (auto const &btn : _guiElement) {
		if (btn.second->isPressed()) {
			btnName = btn.first;
		}
	}
	keyCode.first = _deviceReceiver.getKey();
	keyCode.second = btnName;
}

bool	Irrlicht::isEvent() const
{
	for (auto const &btn : _guiElement) {
		if (btn.second->isPressed()) {
			return true;
		}
	}
	return _deviceReceiver.isEvent();
}

void Irrlicht::loadModels(std::map<std::string, Data> &models)
{
	_sceneData = models;
	for (auto const &model : models) {
		_sceneElement.insert({model.first, _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh(model.second.modelPath.c_str()))});
		if (_sceneElement[model.first] == nullptr) {
			continue;
		}
		_sceneElement[model.first]->setMD2Animation(model.second.animationType);
		_sceneElement[model.first]->setPosition(irr::core::vector3df(model.second.pos.x, 0.0f, model.second.pos.y));
		_sceneElement[model.first]->setRotation(irr::core::vector3df(model.second.rot.x, model.second.rot.y, .0f));
		_sceneElement[model.first]->setVisible(model.second.isVisible);
		if (!model.second.texturePath.empty()) {
			_sceneElement[model.first]->setMaterialTexture(0, _driver->getTexture(model.second.texturePath.c_str()));
		}
	}
}

void Irrlicht::updateModels(std::map<std::string, Data> &models)
{
	Data	tmpData;

	for (auto const &currentModel : _sceneData) {
		tmpData = models[currentModel.first];
		if (tmpData.animationType != currentModel.second.animationType
			|| !Tools::cmpPos(tmpData.pos, _sceneData[currentModel.first].pos)
			|| !Tools::cmpRot(tmpData.rot, _sceneData[currentModel.first].rot)) {
			_sceneElement[currentModel.first]->setMD2Animation(tmpData.animationType);
			_sceneElement[currentModel.first]->setPosition(Tools::posToVec(tmpData.pos));
			_sceneElement[currentModel.first]->setRotation(irr::core::vector3df(tmpData.rot.x, tmpData.rot.y, .0f));
			_sceneElement[currentModel.first]->setVisible(tmpData.isVisible);
			_sceneData[currentModel.first] = tmpData;
		}
	}
}

void Irrlicht::loadGuis(std::map<std::string, Data> &guis)
{
	std::wstring	tmpString;
	irr::gui::IGUIStaticText	*tmpText;
	irr::gui::IGUIButton		*tmpBtn;
	irr::core::dimension2d<irr::u32>	textSize;
	irr::core::rect<irr::s32>	rect;

	_guiData = guis;
	for (auto const &gui : guis) {
		Tools::displayVerbose(_verbose, "Add GUI element: " + gui.first);
		tmpString = std::wstring(gui.second.modelPath.begin(), gui.second.modelPath.end());
		textSize = _font->getDimension(tmpString.c_str());
		rect = irr::core::rect<irr::s32>(gui.second.pos.x, gui.second.pos.y, gui.second.pos.x + textSize.Width + 5, gui.second.pos.y + textSize.Height + 5);
		if (gui.second.isBnt) {
			tmpBtn = _gui->addButton(rect, nullptr, -1, tmpString.c_str());
			_guiElement.insert({ gui.first, tmpBtn });
		} else {
			_textElement.insert({ gui.first, _gui->addStaticText(tmpString.c_str(), rect, _verbose, true, nullptr, -1, false) });
			tmpText = (irr::gui::IGUIStaticText *)_textElement[gui.first];
			tmpText->setVisible(gui.second.isVisible);
			tmpText->setOverrideColor(irr::video::SColor(255, 255, 255, 255));
		}
	}
}

void Irrlicht::updateGuis(std::map<std::string, Data> &guis)
{
	std::wstring	tmpString;
	irr::gui::IGUIStaticText	*tmpText;
	irr::core::dimension2d<irr::u32>	textSize;
	irr::core::rect<irr::s32>	rect;

	for (auto const &gui : _guiData) {
		if (!gui.second.isBnt) {
			_textElement[gui.first]->setVisible(false);
			tmpString = std::wstring(gui.second.modelPath.begin(), gui.second.modelPath.end());
			textSize = _font->getDimension(tmpString.c_str());
			rect = irr::core::rect<irr::s32>(gui.second.pos.x, gui.second.pos.y, gui.second.pos.x + textSize.Width + 5, gui.second.pos.y + textSize.Height + 5);
			_textElement[gui.first] = _gui->addStaticText(tmpString.c_str(), rect, _verbose, true, nullptr, -1, false);
			tmpText = (irr::gui::IGUIStaticText *)_textElement[gui.first];
			tmpText->setVisible(gui.second.isVisible);
			tmpText->setOverrideColor(irr::video::SColor(255, 255, 255, 255));
		}
	}
	_guiData = guis;
}

void Irrlicht::getMap(std::vector<std::vector<char>> &map)
{
	size_t	x = 0;
	size_t	y = 0;

	generateGround();
	if (map.empty()) {
		return;
	}
	for (auto const &line : map) {
		x = 0;
		for (auto const &element : line) {
			Tools::displayVerbose(_verbose,std::string(1, element), false);
			if (element != '*' && element != '#') {
				_sceneCube.push_back(_sceneManager->addCubeSceneNode(_cubeSize));
				_sceneCube.back()->setPosition(irr::core::vector3df(x * _cubeSize, 0, y * _cubeSize));
				_sceneCube.back()->setVisible(false);
				x++;
				continue;
			}
			_sceneCube.push_back(_sceneManager->addCubeSceneNode(_cubeSize));
			_sceneCube.back()->setPosition(irr::core::vector3df(x * _cubeSize, 0, y * _cubeSize));
			_sceneCube.back()->setMaterialTexture(0, _driver->getTexture( element == '#' ? "texture/cobble.png" : "texture/wall.png"));
			x++;
		}
		y++;
		Tools::displayVerbose(_verbose, "");
	}
	Tools::displayVerbose(_verbose, "\n");
}

void	Irrlicht::changeCameraPosition(Tools::vector3d &pos, Tools::vector3d &rot)
{
	auto cameraPos = _camera->getPosition();
	auto cameraRot = _camera->getRotation();

	if (cameraPos.X != pos.x || cameraPos.Y != pos.y || cameraPos.Z != pos.z) {
		_camera->setPosition(irr::core::vector3df(pos.x, pos.y, pos.z));
	}
	if (cameraRot.X != rot.x || cameraRot.Y != rot.y || cameraRot.Z != rot.z) {
		_camera->setTarget(irr::core::vector3df(rot.x, rot.y, rot.z));
	}
}

void Irrlicht::generateGround()
{
	for (auto y = -70; y < 70; y++) {
		for (auto x = -70; x < 40; x++) {
			_sceneCube.push_back(_sceneManager->addCubeSceneNode(_cubeSize));
			_sceneCube.back()->setPosition(irr::core::vector3df(x * _cubeSize, -_cubeSize, y * _cubeSize));
			_sceneCube.back()->setMaterialTexture(0, _driver->getTexture("texture/grass.jpeg"));
		}
	}
	_sceneManager->addSkyDomeSceneNode(_driver->getTexture("texture/dome.jpg"));
	generateTrees(50);
}

void	Irrlicht::generateTrees(int nbTree)
{
	float	x;
	float	y;

	srand((unsigned int)time(nullptr));
	for (auto count = 0; count < nbTree; count++) {
		x = Tools::randPos(std::make_pair<float, float>(0.0f, _cubeSize * 15.0f));
		y = Tools::randPos(std::make_pair<float, float>(0.0f, _cubeSize * 15.0f));
		y = Tools::randPos(std::make_pair<float, float>(0.0f, _cubeSize * 15.0f));
		for (auto z = 0; z < 5; z++) {
			_sceneCube.push_back(_sceneManager->addCubeSceneNode(_cubeSize));
			_sceneCube.back()->setPosition(irr::core::vector3df(x, z * _cubeSize, y));
			_sceneCube.back()->setMaterialTexture(0, _driver->getTexture("texture/wood.png"));
		}
		_sceneCube.push_back(_sceneManager->addCubeSceneNode(_cubeSize * 5));
		_sceneCube.back()->setPosition(irr::core::vector3df(x, 6 * _cubeSize, y));
		_sceneCube.back()->setMaterialTexture(0, _driver->getTexture("texture/leaf.png"));
	}
}

void	Irrlicht::displayMap(std::vector<std::vector<char>> &map)
{
	if (!_verbose || map.empty()) {
		return;
	}
	for (auto const &line : map) {
		for (auto const &elem : line) {
			std::cerr << elem;
		}
		std::cerr << std::endl;
	}
	std::cerr << std::endl;
}

void Irrlicht::updateMap(std::vector<std::vector<char>> &map, std::unique_ptr<ISound> &sound)
{
	irr::core::vector3df	tmpVec;
	int	x;
	int	z;

	for (auto &cube : _sceneCube) {
		tmpVec = cube->getPosition();
		if (tmpVec.Y == 0.0f && tmpVec.X >= 0 && tmpVec.Z >= 0 && tmpVec.X / _cubeSize <= 15 && tmpVec.Z / _cubeSize <= 15 ) {
			x = tmpVec.X / _cubeSize;
			z = tmpVec.Z / _cubeSize;
			if (map[x][z] == ' ')
				cube->setVisible(false);
			else if (map[x][z] == '#') {
				cube->setMaterialTexture(0, _driver->getTexture( "texture/cobble.png"));
				cube->setVisible(true);
			}
		}
	}
	checkMove(map, sound);
	checkPlayerDied(map, sound);
}

bool	Irrlicht::checkPlayer(char player, std::vector<std::vector<char>> &map)
{
	for (auto const &line : map) {
		for (auto const &elem : line) {
			if (elem == player) {
				return true;
			}
		}
	}
	return false;
}

bool	Irrlicht::checkPlayerDied(std::vector<std::vector<char>> &map, std::unique_ptr<ISound> &sound)
{
	if (!checkPlayer('C', map) && _sceneElement.find("player3") != _sceneElement.end() && _sceneElement["player3"]->isVisible()) {
		_sceneElement["player3"]->setVisible(false);
		sound->addSound("media/death.ogg", 50);
	}
	if (!checkPlayer('D', map) && _sceneElement.find("player4") != _sceneElement.end() && _sceneElement["player4"]->isVisible()) {
		_sceneElement["player4"]->setVisible(false);
		sound->addSound("media/death.ogg", 50);
	}
	if (!checkPlayer('B', map) && _sceneElement.find("player2") != _sceneElement.end() && _sceneElement["player2"]->isVisible()) {
		_sceneElement["player2"]->setVisible(false);
		sound->addSound("media/death.ogg", 50);
	}
}

void Irrlicht::removeBombAt(int x, int y, int z)
{
	for (auto &cube : _sceneCube) {
		if (cube->getPosition().X == x && cube->getPosition().Y == y && cube->getPosition().Z == z) {
			cube->setVisible(false);
		}
	}
}

void Irrlicht::addBombAt(int x, int y, int z)
{
	for (auto &cube : _sceneCube) {
		if (cube->getPosition().X == x && cube->getPosition().Y == y && cube->getPosition().Z == z) {
			cube->setVisible(true);
			cube->setMaterialTexture(0, _driver->getTexture("texture/tnt.jpg"));
		}
	}
}

void	Irrlicht::checkMove(std::vector<std::vector<char>> &map, std::unique_ptr<ISound> &sound)
{
	auto z = 0;
	auto x = 0;

	for (auto &line : map) {
		x = 0;
		for (auto &elem : line) {
			updatePlayerMove(map, x, z, elem, sound);
			if (elem == '1' || elem == '2') {
				addBombAt(z * _cubeSize, 0, x * _cubeSize);
				sound->addSound("media/explosion.ogg", 50);
			} else if (elem == '3') {
				removeBombAt(z * _cubeSize, 0, x * _cubeSize);
			}
			x++;
		}
		z++;
	}
}

void Irrlicht::updatePlayerMove(std::vector<std::vector<char>> &map, int x, int z, char elem, std::unique_ptr<ISound> &sound)
{
	irr::core::vector3df	tmp;

	if (elem == 'B' && _sceneElement.find("player2") != _sceneElement.end()) {
		tmp = _sceneElement["player2"]->getPosition();
		if (tmp.X != z * _cubeSize || tmp.Z != x * _cubeSize) {
			_sceneElement["player2"]->setPosition(irr::core::vector3df(z * _cubeSize, 0, x * _cubeSize));
			sound->addSound("media/walk2.ogg", 5);
		}
	}
	if (elem == 'C' && _sceneElement.find("player3") != _sceneElement.end()) {
		tmp = _sceneElement["player2"]->getPosition();
		if (tmp.X != z * _cubeSize || tmp.Z != x * _cubeSize) {
			_sceneElement["player3"]->setPosition(irr::core::vector3df(z * _cubeSize, 0, x * _cubeSize));
			sound->addSound("media/walk3.ogg", 5);
		}
	}
	if (elem == 'D' && _sceneElement.find("player4") != _sceneElement.end()) {
		tmp = _sceneElement["player2"]->getPosition();
		if (tmp.X != z * _cubeSize || tmp.Z != x * _cubeSize) {
			_sceneElement["player4"]->setPosition(irr::core::vector3df(z * _cubeSize, 0, x * _cubeSize));
			sound->addSound("media/walk4.ogg", 5);
		}
	}
}