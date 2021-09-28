#include "Entity.h"
#include "Map.h"
#ifndef EntityWalk_h
#define EnitityWalk_h
#pragma once

/*Класс ходячих существ, наследуется от класса существ, имеет поля x, y - которые являются координатами левого верхнего
края существа, dx, dy - скорость по x и y, метод AnimationWalk - анимацию ходьбы в 4 стороны, Update - вызывается каждый фрейм,
отвечает за движение существа, CollisionWithMap - обработка столкновения с картой, конструктор имеет параметр name */

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


