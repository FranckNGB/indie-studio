/*
** EPITECH PROJECT, 2021
** bomberman
** File description:
** Created by asianpw,
*/
#ifndef BOMBERMAN_DEVICERECEIVER_HPP
#define BOMBERMAN_DEVICERECEIVER_HPP

#include <irr/irrlicht.h>

class DeviceReceiver : public irr::IEventReceiver {
public:
	explicit DeviceReceiver(bool verbose);
	bool OnEvent(const irr::SEvent &event) override;
	bool IsKeyDown(irr::EKEY_CODE keyCode) const;
	int	getKey();
	bool	isEvent() const;

private:
	int	_key;
	bool _keyDown[irr::KEY_KEY_CODES_COUNT];
	bool _verbose;
};

#endif //BOMBERMAN_DEVICERECEIVER_HPP
