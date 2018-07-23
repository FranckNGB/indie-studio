/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_MENU_HPP
#define BOMBERMAN_MENU_HPP

#include "IScene.hpp"
#include "GenerateMap.hpp"
#include "vector3d.hpp"

class Menu : public IScene{
public:
	explicit Menu(bool);
	~Menu() override = default;
	std::map<std::string, Data> &getModels() override;
	std::map<std::string, Data> &getGuis() override;
	void compute(std::pair<int, std::string> &keyCode) override;
	IScene *newScene() override;
	void checkEvents(std::pair<int, std::string> &) override;
	std::vector<std::vector<char>> &getMap() override;
	Tools::vector3d &getCameraPos() override;
	Tools::vector3d &getCameraRot() override;

private:
	std::map<std::string, Data>	_models;
	std::map<std::string, Data>	_guis;
	GenerateMap	_map;
	bool	_verbose;
	bool	_change;
	bool	_sens;
	Tools::vector3d	_cameraPos;
	Tools::vector3d	_cameraRot;
public:
	std::string getSound() override;

private:
	IScene	*_scene;
};

#endif //BOMBERMAN_MENU_HPP
