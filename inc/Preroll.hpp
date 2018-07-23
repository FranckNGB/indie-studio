/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/

#ifndef BOMBERMAN_PREROLL_HPP
#define BOMBERMAN_PREROLL_HPP

#include <string>
#include <map>
#include "IScene.hpp"
#include "vector3d.hpp"

class Preroll : public IScene {
public:
	explicit Preroll(bool);
	~Preroll() override = default;
	std::map<std::string, Data> &getModels() override;
	void compute(std::pair<int, std::string> &) override;
	IScene	*newScene() override;
	void checkEvents(std::pair<int, std::string> &) override;
	std::map<std::string, Data> &getGuis() override;
	std::vector<std::vector<char>> &getMap() override;
	Tools::vector3d &getCameraPos() override;
	Tools::vector3d &getCameraRot() override;
	std::string getSound() override;

private:
	std::map<std::string, Data>	_models;
	std::map<std::string, Data>	_guis;
	std::vector<std::vector<char>>	_map;
	Tools::vector3d	_cameraPos;
	Tools::vector3d	_cameraRot;
	bool	_change;
	bool	_verbose;
};

#endif //BOMBERMAN_PREROLL_HPP
