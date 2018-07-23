/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_GRAPHPARAMS_HPP
#define BOMBERMAN_GRAPHPARAMS_HPP

struct GraphParams {
	bool	vSync;
	bool	fullScreen;
	bool	verbose;
	std::pair<size_t, size_t>	resolution;
	bool	change;
};

#endif //BOMBERMAN_GRAPHPARAMS_HPP
