#include "Bullet.h"
#include <iostream>

Bullet::Bullet(int direction, FloatRect rectbullet, int damage) {
	//������������� ���������� ��� �����������, �������������� ����, �����, �����, ��������
	this->direction = direction;
	this->rectbullet = rectbullet;
	this->damage = damage;
	life = true;
	speed = 0.1;
	//������ �������� ��� ����
	bulletpicture.loadFromFile("images/bullet.png");
	//������������� ����� ��� ��������
	bulletpicture.createMaskFromColor(Color(0, 0, 0));
	//������ ������ � ��������
	texture.loadFromImage(bulletpicture);
	sprite.setTexture(texture);
}

void Bullet::Update(float time, Bullet & bullet, Map & map) {

	//�������� ���� � ������, ���������� �� ����� �������

	for (int i = bullet.rectbullet.top / 32; i < (bullet.rectbullet.top + bullet.rectbullet.height) / 32; i++) {
		for (int j = bullet.rectbullet.left / 32; j < (bullet.rectbullet.left + bullet.rectbullet.width) / 32; j++)
		{
			//���� ������������ � ������ ���� ������, �� ���� ���������

			if (map.map[i][j] == 1 || map.map[i][j] == 2)
			{
				bullet.life = false;
			}

		}
	}

	//�������� ���� � 4 ����������� 1 - ������, 2 - �����, 3 - �����, 4- ����

	if (bullet.direction == 1) {
		bullet.rectbullet.left += bullet.speed * time;
	}
	else if (bullet.direction == 2) {
		bullet.rectbullet.top -= bullet.speed * time;
	}
	else if (bullet.direction == 3) {
		bullet.rectbullet.left -= bullet.speed * time;
	}
	else if (bullet.direction == 4) {
		bullet.rectbullet.top += bullet.speed * time;
	}

	//������������� ������� ������� ����

	bullet.sprite.setPosition(bullet.rectbullet.left, bullet.rectbullet.top);
}