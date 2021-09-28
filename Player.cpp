#include "Player.h"

Player::Player(std::string name) : EntityWalkShoot(name) {
	this->name = name;
	bulletsnum = 0;
}

void Player::AnimationPlayer(Player & player) {

}
 
void Player::Update(float time, EntityWalk& walk, Map& map, float CurrentFrame) {
	//�������� Update
	EntityWalkShoot::Update(time, walk , map, CurrentFrame);
}

void Player::CollisionWithMap(EntityWalk& walk, Map& map) {
	//�������� CollisionWithMap
	EntityWalkShoot::CollisionWithMap(walk, map);
}

void Player::Upgrade(Player& player) {

	//���� ���������� ����� ������ 300 � ��� ������ �� ����������

	if (player.score >= 300 && player.name != "PlayerUp") {

		/*����������� ���������� name ����� ���, ��� ����������� ����������� ���������,
		����� ��������� ����� ��������*/

		player.name = "PlayerUp";
		player.hp = 200;
		player.score -= 50;
		player.damage = 20;
	}
	
	//������� ���������

	else if (player.score >= 500 && player.name == "PlayerUp") {
		player.hp = 400;
		player.damage = 40;
		player.score -= 500;
	}

	//������� �������������� �� �� 200 ������

	else if (player.score >= 100 && player.name == "PlayerUp") {
		player.hp = 200;
		player.score -= 100;
	}

	
}