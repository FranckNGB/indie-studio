/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/

#include "../inc/Preroll.hpp"
#include "../inc/GenerateMap.hpp"
#include "../inc/Menu.hpp"
#include "../inc/keyCodes.hpp"

Preroll::Preroll(bool verbose) : _change(false), _verbose(verbose), _cameraPos({100.0f, 0.0f, 20.0f}), _cameraRot({ 0, 0, 0})
{
	_models.insert({"player", { {-200, 30}, {0, -90}, "texture/characters/ziggs.png", "texture/characters/ziggs.md3", irr::scene::EMAT_STAND, false, true }});
	_guis.insert({"pass", { {370, 500}, {0, 180}, "", "Press M to pass", irr::scene::EMAT_STAND, false, true }});
}

void	Preroll::compute(std::pair<int, std::string> &keyCode)
{
	_models["player"].animationType = irr::scene::EMAT_RUN;
	_models["player"].pos.x++;
	if (_models["player"].pos.x > 50) {
		_change = true;
	}
	_cameraPos.y += 0.1f;
}

std::vector<std::vector<char>>	&Preroll::getMap()
{
	return _map;
}

void	Preroll::checkEvents(std::pair<int, std::string> &keyCode)
{
}

std::map<std::string, Data> &Preroll::getGuis()
{
	return _guis;
}

std::map<std::string, Data>	&Preroll::getModels()
{
	return _models;
}

IScene*	Preroll::newScene()
{
	return !_change ? nullptr : new Menu(_verbose);
}

Tools::vector3d &Preroll::getCameraPos()
{
	return _cameraPos;
}

Tools::vector3d &Preroll::getCameraRot()
{
	return _cameraRot;
}

std::string Preroll::getSound()
{
	return "media/preroll.ogg";
}
