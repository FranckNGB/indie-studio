/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/

#include <iostream>
#include "../inc/DeviceReceiver.hpp"
#include "../inc/Tools.hpp"

DeviceReceiver::DeviceReceiver(bool verbose) : _keyDown{ false }, _verbose(verbose)
{
}

bool	DeviceReceiver::OnEvent(const irr::SEvent &event)
{
	_key = -1;
	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		if (event.KeyInput.Key == irr::KEY_ESCAPE) {
			_keyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
		} else {
			_key = event.KeyInput.Key;
		}
		Tools::displayVerbose(_verbose, "Key catch by DeviceReceiver.");
		return true;
	}
	return false;
}

bool DeviceReceiver::IsKeyDown(irr::EKEY_CODE keyCode) const
{
	return _keyDown[keyCode];
}

int DeviceReceiver::getKey()
{
	int tmp;

	tmp = _key;
	_key = -1;
	return tmp;
}

bool DeviceReceiver::isEvent() const
{
	return _key != -1;
}