#include "Entity.h"
#include "Map.h"
#ifndef EntityWalk_h
#define EnitityWalk_h
#pragma once

/*����� ������� �������, ����������� �� ������ �������, ����� ���� x, y - ������� �������� ������������ ������ ��������
���� ��������, dx, dy - �������� �� x � y, ����� AnimationWalk - �������� ������ � 4 �������, Update - ���������� ������ �����,
�������� �� �������� ��������, CollisionWithMap - ��������� ������������ � ������, ����������� ����� �������� name */

class EntityWalk : public Entity
{
protected:
	void AnimationWalk(EntityWalk& walk, float time, float CurrentFrame);
	void Update(float time, EntityWalk& walk, Map& map, float CurrentFrame);
	void CollisionWithMap(EntityWalk& walk, Map& map);
public:
	int x, y;
	float dx, dy;
	EntityWalk(){}
	EntityWalk(std::string name);
};


#endif


