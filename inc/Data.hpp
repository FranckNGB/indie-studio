/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef DATA_HPP
#	define DATA_HPP

#include <string>
#include <irr/IAnimatedMeshMD2.h>
#include "Position.hpp"
#include "Rotation.hpp"

struct Data {
	Position	pos;
	Rotation	rot;
	std::string	texturePath;
	std::string	modelPath;
	irr::scene::EMD2_ANIMATION_TYPE	animationType;
	bool		isBnt;
	bool		isVisible;
	char		charToPerso;
};

#endif //BOMBERMAN_DATA_HPP
