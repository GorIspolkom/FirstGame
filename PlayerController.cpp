#include "PlayerController.h"

void PlayerController::Update(float time, Player& player, float CurrentFrame, Camera & cam, Map & map) {

	//���������� �������� �����
	CurrentFrame += 0.05 * time;

	//������� �� �������� � �� ��������


	if (player.guntime <= 5) {
		player.guntime += player.gunrange;
	}

	//���������� ���������� �� WASD

	if (Keyboard::isKeyPressed(Keyboard::D)){
		player.dx = 0.05;
	}
	else if (Keyboard::isKeyPressed(Keyboard::W)){
		player.dy = -0.05;
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)){
		player.dx = -0.05;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)){
		player.dy = 0.05;
	}

	//������� ��������� �� G

	else if (Keyboard::isKeyPressed(Keyboard::G)) {
		player.Upgrade(player);
	}

	//�������� �� ���������, ��������� � ������ ���� ����� ������� ����, �������� ����� ��������, ����������� ���������� ����

	else if (Keyboard::isKeyPressed(Keyboard::Right) && player.guntime >= 5){
		player.bullets.push_back(new Bullet(1, FloatRect(player.rect.left, player.rect.top, 16, 16), player.damage));
		player.guntime = 0;
		player.bulletsnum++;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up) && player.guntime >= 5) {
		player.bullets.push_back(new Bullet(2, FloatRect(player.rect.left, player.rect.top, 16, 16), player.damage));
		player.guntime = 0;
		player.bulletsnum++;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left) && player.guntime >= 5) {
		player.bullets.push_back(new Bullet(3, FloatRect(player.rect.left, player.rect.top, 16, 16), player.damage));
		player.guntime = 0;
		player.bulletsnum++;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) && player.guntime >= 5) {
		player.bullets.push_back(new Bullet(4, FloatRect(player.rect.left, player.rect.top, 16, 16), player.damage));
		player.guntime = 0;
		player.bulletsnum++;
	}

	//������� ������ � ����������� �� ��������� ���������

	cam.MoveCamera(player.sprite.getPosition().x, player.sprite.getPosition().y);

	//���������� ������ �� ��������� ������� ����

	for (int i = 0; i < player.bulletsnum; i++) {

		//���� ���� ����, �� �������� ��� ������ ����� Update

		if (player.bullets[i]->life) {
			player.bullets[i]->Update(time, *player.bullets[i], map);
		}

		//������� ������ ����, ������� ������� ���� �� ������ � ��������� ���������� ����

		else {
			delete player.bullets[i];
			player.bullets.erase(player.bullets.cbegin() + i);
			player.bulletsnum--;
		}
	}

	//�������� Update ������

	player.Update(time, player, map, CurrentFrame);
}