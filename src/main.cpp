/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Main
*/

#include <memory>
#include <iostream>
#include "../inc/Params.hpp"
#include "../inc/Core.hpp"
#include "../inc/GenerateMap.hpp"

int main(int ac, char *av[])
{
	std::unique_ptr<Params>	params(new Params(ac, av));
	std::unique_ptr<Core>	core;


	if (params->parse()) {
		try {
			core = std::make_unique<Core>(params);
			core->compute();
		} catch (const std::runtime_error &e) {
			std::cerr << e.what() << std::endl;
			return 84;
		}
	}
	return 0;
}
