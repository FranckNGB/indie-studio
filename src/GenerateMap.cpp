/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by j-f,
*/

#include "../inc/GenerateMap.hpp"

GenerateMap::GenerateMap(size_t nbrplayer, size_t nbria)
{
	InitMap();
	place_unbreakable_wall_width();
	place_unbreakable_wall_height();
	place_target_wall();
	setPlayeronMap(nbrplayer);
	setIaonMap(nbria);
	set_place_for_players();
}

GenerateMap::~GenerateMap()
{
}

int	GenerateMap::getWidth(void)
{
	return width;
}

int	GenerateMap::getHeight(void)
{
	return height;
}

int	GenerateMap::getNbrwall(void)
{
	return nbr_wall;
}

std::vector<std::vector<char>>	&GenerateMap::getMap(void)
{
	return BombermanMap;
}

void	GenerateMap::print_map(void)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout<<BombermanMap[i][j];
		}
		std::cout<<std::endl;
	}
}

void	GenerateMap::InitMap(void)
{
	BombermanMap.resize(height, std::vector<char>(width));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			BombermanMap[i][j] = '*';
		}
	}
}

void	GenerateMap::place_unbreakable_wall_height(void)
{
	for (int i = 0; i < height; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j < width - 1; j++) {
				BombermanMap[i][j] = ' ';
			}
		}
	}
}

void	GenerateMap::place_unbreakable_wall_width(void)
{
	for (int i = 1; i < height - 2 ; i++) {
		for (int j = 0; j < width - 1; j++) {
			if (j % 2 != 0 ) {
				BombermanMap[i][j] = ' ';
			}
		}
	}
}

void	GenerateMap::place_target_wall(void)
{
	std::mt19937	rng;
	std::uniform_int_distribution<std::mt19937::result_type>	randWidth(0, width - 1);
	std::uniform_int_distribution<std::mt19937::result_type>	randHeight(0, (int)(height - 1));
	unsigned long	i, j;

	rng.seed(std::random_device()());
	for (int z = 0; z <= nbr_wall; z++) {
		i = randHeight(rng);
		j = randWidth(rng);
		while (BombermanMap[i][j] && BombermanMap[i][j] != ' ') {
			i = randHeight(rng);
			j = randWidth(rng);
		}
		BombermanMap[i][j] = '#';
	}
}

void	GenerateMap::set_place_for_players(void)
{
	int	x = 0;
	int	y = 0;
	int	index;

	while (x != height)
	{
		y = 0;
		while (y != width)
		{
			if (BombermanMap[x][y] >= 65 && BombermanMap[x][y] <= 68) {
				index = 1;
				while (index < 3)
				{
					if ((x - index) >= 0 &&
						BombermanMap[x - index][y] !=
							'*')
						BombermanMap[x -
							index][y] = ' ';
					if ((x + index) < height &&
					BombermanMap[x + index][y] != '*')
					BombermanMap[x + index][y] = ' ';
					if ((y - index) >= 0 &&
					BombermanMap[x][y - index] != '*')
					BombermanMap[x][y - index] = ' ';
					if ((y + index) < width &&
					BombermanMap[x][y + index] != '*')
					BombermanMap[x][y + index] = ' ';
				index++;
				}
			}
			y++;
		}
		x++;
	}
}

void	GenerateMap::setPlayeronMap(int nbrPlayer)
{
	if (nbrPlayer >= 1)
		BombermanMap[1][1] = 'A';
	if (nbrPlayer >= 2)
		BombermanMap[1][width - 2] = 'B';
	if (nbrPlayer >= 3)
		BombermanMap[height - 2][1] = 'C';
	if (nbrPlayer >= 4)
		BombermanMap[height - 2][width - 2] = 'D';
}

void	GenerateMap::setIaonMap(int nbrIa)
{
	if (nbrIa >= 1)
		BombermanMap[1][width - 2] = 'B';
	if (nbrIa >= 2)
		BombermanMap[height - 2][1] = 'C';
	if (nbrIa == 3)
		BombermanMap[height - 2][width - 2] = 'D';
}