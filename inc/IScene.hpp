/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_ISCENE_HPP
#define BOMBERMAN_ISCENE_HPP

#include <map>
#include <vector>
#include "Data.hpp"
#include "vector3d.hpp"

class IScene {
public:
	virtual ~IScene() = default;
	virtual std::map<std::string, Data>	&getModels() = 0;
	virtual std::map<std::string, Data>	&getGuis() = 0;
	virtual std::vector<std::vector<char>>	&getMap() = 0;
	virtual Tools::vector3d	&getCameraPos() = 0;
	virtual Tools::vector3d	&getCameraRot() = 0;
	virtual std::string	getSound() = 0;
	virtual void	compute(std::pair<int, std::string> &) = 0;
	virtual IScene	*newScene() = 0;
	virtual void	checkEvents(std::pair<int, std::string> &) = 0;
};

#endif //BOMBERMAN_ISCENE_HPP
