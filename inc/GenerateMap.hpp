/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by j-f,
*/
#ifndef BOMBERMAN_GENERATEMAP_HPP
#define BOMBERMAN_GENERATEMAP_HPP

#include <iostream>
#include <vector>
#include <random>
#include <irr/driverChoice.h>
#include "../inc/IPlayer.hpp"

using namespace irr;

typedef struct	s_coord
{
	int	x;
	int	y;
}		t_coord;

class	GenerateMap
{
	private:
		int	width = 15;
		int	height = 15;
		int	nbr_wall = (width * height) / 2;
		std::vector<std::vector<char>>	BombermanMap;

	public:
		GenerateMap(size_t , size_t );
		~GenerateMap();
		int	getWidth();
		int	getHeight();
		int	getNbrwall();
		t_coord	getPlayerPlace();
		t_coord	getIaPlace();
		std::vector<std::vector<char>>	&getMap();
		void	InitMap();
		void	print_map();
		void	place_unbreakable_wall_width();
		void	place_unbreakable_wall_height();
		void	place_target_wall();
		void	set_place_for_players();
		void	place_player(size_t);
		void	place_ia(size_t);
		void	setPlayeronMap(int);
		void	setIaonMap(int);
};

#endif //BOMBERMAN_GENERATEMAP_HPP
