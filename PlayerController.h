#include "Player.h"
#include "Camera.h"
#ifndef PlayerController_h
#define PlayerController_h
#pragma once

/*Класс контроллера игрока, метод Update вызывается каждый фрейм, отвечает за управление персонажем*/

class PlayerController
{
public:
	PlayerController(){}
	void Update(float time, Player& player, float CurrentFrame, Camera & cam, Map & map);
};

#endif

