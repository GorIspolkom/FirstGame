#include "EntityWalk.h"
#ifndef  EntityWalkShoot_h
#define  EntityWalkShoot_h
#pragma once

/*����� ���������� �������, ����������� �� ������� �������, ����� ���� gunrange - ���������� ��� �����������,
guntime - ����� ��������, damage - ���� �� ����, ������ AnimationShoot - �������� ��������, Update - ������ ������ �����, 
CollisionWithMap - �������� � ������, ����������� ����� �������� name*/

class EntityWalkShoot : public EntityWalk
{
protected:
	void AnimationShoot(EntityWalkShoot & ent, float time, float CurrentFrame);
	void Update(float time, EntityWalk& walk, Map& map, float CurrentFrame);
	void CollisionWithMap(EntityWalk& walk, Map& map);
public:
	float gunrange;
	float guntime;
	int damage;
	EntityWalkShoot(){}
	EntityWalkShoot(std::string name);
};

#endif 

