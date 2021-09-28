#include "Player.h"
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <math.h>
#ifndef  NonShootMob_h
#define NonShootMob_h
#pragma once

using namespace std;

/*Класс не стреяющих мобов, наследуется от класса ходящих существ, имеет метод Update, который отвечает за движение моба,
mapposition - вектор пар позиций игрок по y, x, damage - урон, scoreperdeath - очки, которые получается игрок за убийство*/

class NonShootMob : public EntityWalk
{
public:
	vector<pair<int,int>> mapposition;
	int damage;
	int scoreperdeath;
	~NonShootMob(){}
	NonShootMob(){}
	NonShootMob(std::string name);
	void Update(Player&player, float time, NonShootMob& walk, Map& map, float CurrentFrame);
};

//###################################PATHFINDING###################################

//Класс поиск пути через алгоритм A*

class PathFinding {

public:

	//Количество строк
	static int const  ROW = 20;
	//Количество столбцов
	static int const  COL = 20;
	//Пара int значений для координат
	typedef pair<int, int> Pair;
	//Пара значений
	typedef pair<double, pair<int, int>> pPair;
	//Структура клетки
	struct cell;
	//Метод проверки находится ли ячейка в допустимом диапазоне
	bool isValid(int row, int col);
	//Метод проверки блокируется ли путь
	bool isUnBlocked(Map& map, int row , int col);
	//Достигнута ли точка назначения
	bool isDestination(int row, int col,  Pair dest);
	//Подсчет H 
	double calculateHValue(int row, int col, Pair dest);
	//Метод разметки пути
	void tracePath(NonShootMob& mob, cell cellDetails[][COL], Pair dest);
	//Главный метод поиска 
	void aStarSearch(NonShootMob& mob, Map& map, Pair src, Pair dest);

};


#endif 