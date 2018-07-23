/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/

#include <iostream>
#include "../inc/Tools.hpp"

irr::core::vector3df Tools::posToVec(Position &position)
{
	return irr::core::vector3df(position.x, .0f, position.y);
}

bool Tools::cmpRot(Rotation &p1, Rotation &p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

bool Tools::cmpPos(Position &p1, Position &p2)
{
	return p1.x == p2.x && p1.y == p2.y;
}

void Tools::displayVerbose(bool verbose, std::string const &message, bool endl)
{
	if (!verbose)
		return;
	std::cerr << message;
	if (endl) {
		std::cerr << std::endl;
	}
}

float	Tools::randPos(std::pair<float, float> noManLand)
{
	static bool	neg = true;
	static float	pos = 0.0f;
	int	change;

	if (pos  == 0.0f) {
		srand(time(nullptr));
	}
	if (neg)
		pos = -(rand() % (500) + 1);
	else {
		do {
			pos = rand() % (500) + 1;
		} while (pos >= noManLand.first && pos <= noManLand.second);
	}
	change = rand() % (2) + 1;
	if (change == 1)
		neg = !neg;
	return pos;
}