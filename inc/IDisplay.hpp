/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Display Interface
*/
#ifndef IDISPLAY_HPP
#define IDISPLAY_HPP

#include <map>
#include <vector>
#include "Data.hpp"
#include "vector3d.hpp"
#include "GraphParams.hpp"
#include "ISound.hpp"

class IDisplay {
public:
	virtual ~IDisplay() = default;
	virtual void	display() = 0;
	virtual void	clear() = 0;
	virtual bool	isOpen() const = 0;
	virtual void	loadModels(std::map<std::string, Data> &) = 0;
	virtual void	updateModels(std::map<std::string, Data> &) = 0;
	virtual void	loadGuis(std::map<std::string, Data> &) = 0;
	virtual void	updateGuis(std::map<std::string, Data> &map) = 0;
	virtual void	getEvents(std::pair<int, std::string> &) = 0;
	virtual void	getMap(std::vector<std::vector<char>> &) = 0;
	virtual void	updateMap(std::vector<std::vector<char>> &, std::unique_ptr<ISound> &) = 0;
	virtual void	displayMap(std::vector<std::vector<char>> &) = 0;
	virtual void	changeCameraPosition(Tools::vector3d &, Tools::vector3d &) = 0;
	virtual bool	isEvent() const = 0;
};

#endif //BOMBERMAN_IDISPLAY_HPP
