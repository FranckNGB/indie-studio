/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_SETTINGS_HPP
#define BOMBERMAN_SETTINGS_HPP

#include <memory>
#include "IScene.hpp"
#include "GenerateMap.hpp"
#include "Params.hpp"
#include "GraphParams.hpp"

class Settings : public IScene {
public:
	explicit Settings(IScene *, GraphParams &);
	std::string getSound() override;
	std::map<std::string, Data> &getModels() override;
	std::map<std::string, Data> &getGuis() override;
	std::vector<std::vector<char>> &getMap() override;
	Tools::vector3d &getCameraPos() override;
	Tools::vector3d &getCameraRot() override;
	void compute(std::pair<int, std::string> &pair) override;
	IScene *newScene() override;
	void checkEvents(std::pair<int, std::string> &pair) override;

private:
	IScene	*_prevScene;
	std::map<std::string, Data>	_models;
	std::map<std::string, Data>	_guis;
	std::vector<std::vector<char>>	_map;
	GraphParams	&_params;
	Tools::vector3d	_cameraPos;
	Tools::vector3d	_cameraRot;
	bool	_verbose;
	bool	_backToPrev;
};

#endif //BOMBERMAN_SETTINGS_HPP
