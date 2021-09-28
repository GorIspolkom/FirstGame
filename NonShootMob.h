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

/*����� �� ��������� �����, ����������� �� ������ ������� �������, ����� ����� Update, ������� �������� �� �������� ����,
mapposition - ������ ��� ������� ����� �� y, x, damage - ����, scoreperdeath - ����, ������� ���������� ����� �� ��������*/

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

//����� ����� ���� ����� �������� A*

class PathFinding {

public:

	//���������� �����
	static int const  ROW = 20;
	//���������� ��������
	static int const  COL = 20;
	//���� int �������� ��� ���������
	typedef pair<int, int> Pair;
	//���� ��������
	typedef pair<double, pair<int, int>> pPair;
	//��������� ������
	struct cell;
	//����� �������� ��������� �� ������ � ���������� ���������
	bool isValid(int row, int col);
	//����� �������� ����������� �� ����
	bool isUnBlocked(Map& map, int row , int col);
	//���������� �� ����� ����������
	bool isDestination(int row, int col,  Pair dest);
	//������� H 
	double calculateHValue(int row, int col, Pair dest);
	//����� �������� ����
	void tracePath(NonShootMob& mob, cell cellDetails[][COL], Pair dest);
	//������� ����� ������ 
	void aStarSearch(NonShootMob& mob, Map& map, Pair src, Pair dest);

};


#endif 