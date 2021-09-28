#include "Player.h"

Player::Player(std::string name) : EntityWalkShoot(name) {
	this->name = name;
	bulletsnum = 0;
}

void Player::AnimationPlayer(Player & player) {

}
 
void Player::Update(float time, EntityWalk& walk, Map& map, float CurrentFrame) {
	//Вызываем Update
	EntityWalkShoot::Update(time, walk , map, CurrentFrame);
}

void Player::CollisionWithMap(EntityWalk& walk, Map& map) {
	//Вызываем CollisionWithMap
	EntityWalkShoot::CollisionWithMap(walk, map);
}

void Player::Upgrade(Player& player) {

	//Если количество очков больше 300 и имя игрока не апдейтнуто

	if (player.score >= 300 && player.name != "PlayerUp") {

		/*Присваиваем переменной name новое имя, для отображения улучшенного персонажа,
		чтобы загрузить новую картинку*/

		player.name = "PlayerUp";
		player.hp = 200;
		player.score -= 50;
		player.damage = 20;
	}
	
	//Покупка улучшений

	else if (player.score >= 500 && player.name == "PlayerUp") {
		player.hp = 400;
		player.damage = 40;
		player.score -= 500;
	}

	//Покупка восстановления хп до 200 единиц

	else if (player.score >= 100 && player.name == "PlayerUp") {
		player.hp = 200;
		player.score -= 100;
	}

	
}