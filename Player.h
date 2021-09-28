#include"EntityWalkShoot.h"
#include "Bullet.h"
#ifndef Player_h
#define Player_h
#pragma once

/* ласс игрока, наследуетс€ от класс стрел€ющих существ, имеет пол€ - вектор пуль, количество пуль, очки,
в констуркторе один параметр name, метод - AnimationPlayer - анимаци€ игрока, Update - вызываетс€ каждый фрейм,
CollisionWithMap - коллизи€ с картой, Upgrade - покупка улучшений дл€ игрока*/


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