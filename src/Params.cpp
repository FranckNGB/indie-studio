/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Parse Params
*/
#include <cstddef>
#include <cstring>
#include <iostream>
#include "../inc/Params.hpp"

Params::Params(int ac, char **av) : _verbose(false), _nbArgs(ac), _av(av), _width(1080), _height(720), _vsync(false), _fullscreen(false)
{
}

bool	Params::getVerbose() const
{
	return _verbose;
}

bool	Params::getFullscreen() const
{
	return _fullscreen;
}

bool	Params::getVsync() const
{
	return _vsync;
}

int	Params::getIndex()
{
	int	i = 0;

	while (_av[i] != NULL) {
		if (strcmp(_av[i], "--size") == 0 || strcmp(_av[i], "-s") == 0) {
			return (i);
		}
		i = i + 1;
	}
	return (0);
}

void	Params::displayHelp() const
{
	std::cerr << "USAGE:" << std::endl;
	std::cerr << "\t\t" << _av[0] << " [options]" << std::endl << std::endl;
	std::cerr << "Here is the list of different options : " <<std::endl;
	std::cerr << std::endl;
	std::cerr << "\t\t      --size [width] [height]\tSet window dimensions" << std::endl;
	std::cerr << "\t\t-v or --verbose\t\t\tPrint all object's information (position and others)" << std::endl;
	std::cerr << "\t\t-f or --fullscreen\t\tUse the fullscreen option" << std::endl;
	std::cerr << "\t\t      --vsync\t\t\tUse Sync the printing of scene" << std::endl;
}

bool	Params::argsExist(const char *arg) const
{
	for (int count = 0; count < _nbArgs; ++count) {
		if (!strcmp(arg, _av[count])) {
			return true;
		}
	}
	return false;
}

bool Params::checkParams(char **arg) const
{
	int	i = 1;

	while (_av[i] != NULL) {
		if (strcmp(_av[i], "-v") != 0 && strcmp(_av[i], "--verbose") != 0
			&& strcmp(_av[i], "-h") != 0 && strcmp(_av[i], "--help") != 0
			&& strcmp(_av[i], "-f") != 0 && strcmp(_av[i], "--fullscreen") != 0
			&& strcmp(_av[i], "--vsync") != 0 && strcmp(_av[i], "--size") != 0
			&& argsExist("--size") == false) {
			std::cerr << "Bad input options. Try ./bomberman --help" << std::endl;
			return false;
		}
		i++;
	}
	return true;
}

bool	Params::parse()
{
	if (checkParams(_av) == false)
		return false;
	if (argsExist("-v") || argsExist("--verbose"))
		_verbose = true;
	if (argsExist("-f") || argsExist("--fullscreen"))
		_fullscreen = true;
	if (argsExist("--vsync"))
		_vsync = true;
	if (argsExist("-h") || argsExist("--help")) {
		displayHelp();
		return false;
	}
	if (argsExist("--size")) {
		if (_av[getIndex() + 1] == NULL || _av[getIndex() + 2] == NULL) {
			std::cerr << "width and height , both of them must be integers" << std::endl;
			return false;
		}
		_width = atoi(_av[getIndex() + 1]);
		_height = atoi(_av[getIndex() + 2]);
		if (_width  <= 0 || _height <= 0) {
			std::cerr << "width and height , both of them must be positive integers" << std::endl;
			return false;
		}
	}
	return true;
}

std::pair<size_t, size_t>	Params::getResolution() const
{
	return std::make_pair(_width, _height);
}