/*
** EPITECH PROJECT, 2021
** cpp_indie_studio
** File description:
** Created by j-f,
*/

#include "../inc/Player.hpp"

Player::Player(char name, std::vector<std::vector<char>> &map)
	: _name(name), _map(map)
{
}

Player::~Player()
{
}

void	Player::setBombDir(int x)
{
	bomb_dir = x;
}

int	Player::getBombDir()
{
	return (bomb_dir);
}

Position	Player::getPlayerPlace()
{
	int	i = 0;
	int	j;

	while (i < 15) {
		j = 0;
		while (j < 15) {
			if (_map[i][j] == _name) {
				pos.x = i;
				pos.y = j;
				return pos;
			}
			j++;
		}
		i++;
	}
}

void	Player::putBomb()
{
	pos = getPlayerPlace();
	if (bomb_dir == 1 && _map[pos.x][pos.y + 1]  && _map[pos.x][pos.y + 1] == ' ') {
		_map[pos.x][pos.y + 1] = '1';
	}
	else if (bomb_dir == 3 && _map[pos.x][pos.y - 1] && _map[pos.x][pos.y - 1] == ' ') {
		_map[pos.x][pos.y - 1] = '1';
	}
	else if (bomb_dir == 0 && _map[pos.x - 1][pos.y] && _map[pos.x - 1][pos.y] == ' ') {
		_map[pos.x - 1][pos.y] = '1';
	}
	else if (bomb_dir == 2 && _map[pos.x + 1][pos.y] && _map[pos.x + 1][pos.y] == ' ') {
		_map[pos.x + 1][pos.y] = '1';
	}
}

void	Player::moveRight(void)
{
	bomb_dir = 1;
	pos = getPlayerPlace();
	if (_map[pos.x][pos.y + 1]  && _map[pos.x][pos.y + 1] == ' ') {
		_map[pos.x][pos.y + 1] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.x = pos.x + 1;
		ver_explosion = true;
	}
	else {
		locked = true;
		return;
	}
}

void	Player::moveLeft(void)
{
	bomb_dir = 3;
	pos = getPlayerPlace();
	if (_map[pos.x][pos.y - 1] && _map[pos.x][pos.y - 1] == ' ') {
		_map[pos.x][pos.y - 1] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.x = pos.x - 1;
		ver_explosion = true;
	}
	else {
		locked = true;
		return;
	}
}

void	Player::moveUp(void)
{
	bomb_dir = 0;
	pos = getPlayerPlace();
	if (_map[pos.x - 1][pos.y] && _map[pos.x - 1][pos.y] == ' ') {
		_map[pos.x - 1][pos.y] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.y = pos.y - 1;
		hor_explosion = true;
	}
	else {
		locked = true;
		return;
	}
}

void	Player::moveDown(void)
{
	bomb_dir = 2;
	pos = getPlayerPlace();
	if (_map[pos.x + 1][pos.y] && _map[pos.x + 1][pos.y] == ' ') {
		_map[pos.x + 1][pos.y] = _name;
		_map[pos.x][pos.y] = ' ';
		pos.y = pos.y + 1;
		hor_explosion = true;
	}
	else {
		locked = true;
		return;
	}
}

bool Player::getStatus()
{
	return locked;
}