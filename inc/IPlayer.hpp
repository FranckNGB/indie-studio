/*
** EPITECH PROJECT, 2021
** cpp_indie_studio
** File description:
** Created by j-f,
*/

#ifndef CPP_INDIE_STUDIO_IPLAYER_HPP
#define CPP_INDIE_STUDIO_IPLAYER_HPP

#include <iostream>
#include <vector>

class IPlayer {
	public:
		virtual ~IPlayer() = default;
		virtual void	moveLeft() = 0;
		virtual void	moveRight() = 0;
		virtual void	moveUp() = 0;
		virtual void	moveDown() = 0;
		virtual void	putBomb() = 0;
};

#endif //CPP_INDIE_STUDIO_IPLAYER_HPP