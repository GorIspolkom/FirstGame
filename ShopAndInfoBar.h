#include "Player.h"
#include <sstream>
#include "Camera.h"
#ifndef ShopAndInfoBar_h
#define ShopAndInfoBar_h
#pragma once

using namespace sf;

/*����� �������� �� ����� ���������� �� ������ �� �����, ����� ShopInfo �������� �� ����� ���������� �����, ���������
�������, ����� Death - �� ����� ������ ����� ������ ������*/

class ShopAndInfoBar
{
public:
	Font font;
	Text playerh, playerscore;
	ShopAndInfoBar();
	void ShowInfo(Player& player, RenderWindow & window, Camera &cam);
	void Death(Player& player);
};

#endif 
