/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_IRRKLANG_HPP
#define BOMBERMAN_IRRKLANG_HPP

#include <map>
#include "../libso/include/irrKlang.h"
#include "ISound.hpp"

class IrrKlang : public ISound {
public:
	IrrKlang();
	void play(std::string const &) override;
	void pause() override;
	void resume() override;
	void clearUnused() override;
	void addSound(std::string const &, int) override;

private:
	irrklang::ISoundEngine*	_engine;
	std::map<std::string, irrklang::ISound *>	_source;
};

#endif //BOMBERMAN_IRRKLANG_HPP
