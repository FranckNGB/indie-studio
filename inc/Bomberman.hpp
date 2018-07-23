/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_BOMBERMAN_HPP
#define BOMBERMAN_BOMBERMAN_HPP

#include "IScene.hpp"
#include "GenerateMap.hpp"
#include "Position.hpp"
#include "Player.hpp"
#include <sstream>

class Bomberman : public IScene {
public:
	Bomberman(bool, size_t, size_t);
	std::map<std::string, Data> &getModels() override;
	std::map<std::string, Data> &getGuis() override;
	std::vector<std::vector<char>> &getMap() override;
	Tools::vector3d &getCameraPos() override;
	Tools::vector3d &getCameraRot() override;
	void	compute(std::pair<int, std::string> &pair) override;
	IScene	*newScene() override;
	void	checkEvents(std::pair<int, std::string> &pair) override;
	void	checkBomb();
	void	bombExplode(Position);
	bool	checkPlayer(char c);
	void	checkGame();
	std::string	getSound() override;

private:
	bool	_verbose;
	Tools::vector3d	_cameraPos;
	Tools::vector3d	_cameraRot;
	std::map<std::string, Data>	_models;
	std::map<std::string, Data>	_guis;
	GenerateMap	_map;
	Position	player, playerrotate;
	Position	ia, ia1, ia2, loose_text;
	int		score = 0;
	long		currentTime;
	int		bombDir;
	bool		_isEnd;
	bool		_change;
	bool		_deathCamera;
	bool		check_b, check_c, check_d, setb, setc, setd;
	bool		_isWin;
};

#endif //BOMBERMAN_BOMBERMAN_HPP
