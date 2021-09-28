#include "Player.h"
#include <sstream>
#include "Camera.h"
#ifndef ShopAndInfoBar_h
#define ShopAndInfoBar_h
#pragma once

using namespace sf;

/*Класс отвечает за вывод информации об игроке на экран, метод ShopInfo отвечает за вывод количества очков, набранных
игроком, метод Death - за вывод экрана после смерти игрока*/

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
