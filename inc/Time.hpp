/*
** EPITECH PROJECT, 2018
** bomberman
** File description:
** Time.hpp
*/

#ifndef BOMBERMAN_TIME_HPP
#define BOMBERMAN_TIME_HPP

#include <chrono>

using ms = std::chrono::milliseconds;
using sc = std::chrono::steady_clock;

inline long	getCurrentTime() {return std::chrono::duration_cast<ms>(sc::now().time_since_epoch()).count();};


#endif //BOMBERMAN_TIME_HPP
