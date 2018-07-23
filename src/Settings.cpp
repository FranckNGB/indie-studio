/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#include "../inc/Settings.hpp"
#include "../inc/keyCodes.hpp"
#include "../inc/Tools.hpp"

Settings::Settings(IScene *prevScene, GraphParams &params)
	: _prevScene(prevScene), _params(params), _verbose(false), _cameraPos({195.0f, 150.0f, 71.0f}), _cameraRot({ 50.0f, 0.0f, 75.0f}), _backToPrev(false)
{
	_guis.insert({"backToMenu", { {0, 0}, {0, 0}, "", "M: Back To Menu", irr::scene::EMAT_STAND, false, true }});
	_guis.insert({"Settings", { {0, 40}, {0, 0}, "", "Enter: Save Settings/Back to previous", irr::scene::EMAT_STAND, false, true }});
	_guis.insert({"Quit", { {0, 80}, {0, 0}, "", "Escape: Quit Game", irr::scene::EMAT_STAND, false, true }});
	_guis.insert({"VSync", { {300, 200}, {0, 180}, "", "VSync", irr::scene::EMAT_STAND, true, true }});
	_guis.insert({"Fullscreen", { {500, 200}, {0, 180}, "", "Fullscreen", irr::scene::EMAT_STAND, true, true }});
}

std::map<std::string, Data> &Settings::getModels()
{
	return _models;
}

std::map<std::string, Data> &Settings::getGuis()
{
	return _guis;
}

std::vector<std::vector<char>> &Settings::getMap()
{
	return _map;
}

Tools::vector3d &Settings::getCameraPos()
{
	return _cameraPos;
}

Tools::vector3d &Settings::getCameraRot()
{
	return _cameraRot;
}

void Settings::compute(std::pair<int, std::string> &pair)
{
}

IScene *Settings::newScene()
{
	if (_backToPrev) {
		return _prevScene;
	}
	return nullptr;
}

void Settings::checkEvents(std::pair<int, std::string> &keyCode)
{
	if (keyCode.first == KeyCode::KEY_ENTER) {
		_backToPrev = true;
	}
	if (keyCode.second == "VSync") {
		_params.vSync = !_params.vSync;
		_params.change = true;
	}
	if (keyCode.second == "Fullscreen") {
		_params.fullScreen = !_params.fullScreen;
		_params.change = true;
	}
}

std::string Settings::getSound()
{
	return "";
}
