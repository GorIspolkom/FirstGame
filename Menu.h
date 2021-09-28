#include <SFML/Graphics.hpp>
#ifndef Menu_h
#define Menu_h
#pragma once

using namespace sf;

class Menu
{
	/* ласс меню, в главной функции main создаетс€ экземпл€р класса и вызываетс€ 
	метод SmallMenu, который отвечает за вывод меню перед игрой, с двум€ "кнопками" - играть и выход*/
public:
	//isGame - отвечает за то, нужно ли начинать игру и грузить следующий уровень
	bool isGame = false;
	//isMenu - убрать меню или нет
	bool isMenu = true;
	Menu(){}
	void SmallMenu();
};

#endif 