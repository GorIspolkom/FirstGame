#include <ctime>
#include <math.h>
#include "NonShootMob.h"
#include "PlayerController.h"
#include "Map.h"
#ifndef MobsContoller_h
#define MobsContoller_h
#pragma once

using namespace std;

/*����� ����������� �����, colwoln - ���������� ����, mobcol - ���������� �����,
spawncoord - ���������� ������ ����� ���� �������� x, y, mobpopl - ��� ����� � �������, Names - �������� �����, 
SpawnMobs - ����� ������ �����, MobControll - �������� ��������� �����*/

class MobsController
{
public:
	int colwoln = 0;
	int mobcol = 0;
	vector<NonShootMob*> mobpool;
	vector<pair<int, int>> spawncoord = {make_pair(7,15), make_pair(8,5), make_pair(2,8), make_pair(5,3), make_pair(10,8)};
	string Names[2] = { "Tikva", "Ghost" };
	MobsController(){}
	void SpawnMobs();
	void MobContoll(Player& player,float time, Map& map, float CurrentFrame);
};


#endif 
