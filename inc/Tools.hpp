/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_TOOLS_HPP
#define BOMBERMAN_TOOLS_HPP

#include <string>
#include <irr/vector3d.h>
#include "Position.hpp"
#include "Rotation.hpp"

namespace Tools {
	bool	cmpPos(Position &, Position &);
	bool	cmpRot(Rotation &, Rotation &);
	irr::core::vector3df	posToVec(Position &);
	void	displayVerbose(bool, std::string const &, bool endl = true);
	float	randPos(std::pair<float, float>);
}

#endif //BOMBERMAN_TOOLS_HPP
