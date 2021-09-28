#include "EntityWalkShoot.h"

EntityWalkShoot::EntityWalkShoot(std::string name) : EntityWalk(name){
	this->name = name;
	//Устанавливаем значения для игрока
	if (name == "Player"){
		gunrange = 0.02;
		guntime = 5;
		damage = 10;
	}
}

void EntityWalkShoot::AnimationShoot(EntityWalkShoot& ent, float time, float CurrentFrame) {

}

void EntityWalkShoot::Update(float time, EntityWalk& walk, Map& map, float CurrentFrame) {
	EntityWalk::Update(time, walk, map,  CurrentFrame);
}

void EntityWalkShoot::CollisionWithMap(EntityWalk& walk, Map& map) {
	EntityWalk::CollisionWithMap(walk,  map);
}