#include "Player.h"
#include "Camera.h"
#ifndef PlayerController_h
#define PlayerController_h
#pragma once

/*����� ����������� ������, ����� Update ���������� ������ �����, �������� �� ���������� ����������*/

class PlayerController
{
public:
	PlayerController(){}
	void Update(float time, Player& player, float CurrentFrame, Camera & cam, Map & map);
};

#endif

