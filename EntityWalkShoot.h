#include "EntityWalk.h"
#ifndef  EntityWalkShoot_h
#define  EntityWalkShoot_h
#pragma once

/* ласс стрел€ющих существ, наследуетс€ от ходичих существ, имеет пол€ gunrange - переменна€ дл€ перезар€дки,
guntime - врем€ стрельбы, damage - урон от пуль, методы AnimationShoot - анимаци€ стрельбы, Update - апдейт каждый фрейм, 
CollisionWithMap - коллизи€ с картой, констурктор имеет параметр name*/

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

