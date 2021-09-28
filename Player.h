#include"EntityWalkShoot.h"
#include "Bullet.h"
#ifndef Player_h
#define Player_h
#pragma once

/*����� ������, ����������� �� ����� ���������� �������, ����� ���� - ������ ����, ���������� ����, ����,
� ������������ ���� �������� name, ����� - AnimationPlayer - �������� ������, Update - ���������� ������ �����,
CollisionWithMap - �������� � ������, Upgrade - ������� ��������� ��� ������*/


class Player : public EntityWalkShoot
{
public:
	vector <Bullet*> bullets;
	int bulletsnum;
	int score = 0;
	Player() {}
	Player(std::string name);
	void AnimationPlayer(Player& player);
	void Update(float time, EntityWalk& walk, Map& map, float CurrentFrame);
	void CollisionWithMap(EntityWalk& walk, Map& map);
	void Upgrade(Player& player);
};

#endif 