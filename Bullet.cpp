#include "Bullet.h"
#include <iostream>

Bullet::Bullet(int direction, FloatRect rectbullet, int damage) {
	//”станавливаем переменные дл€ направлени€, пр€моугольника пули, урона, жизни, скорости
	this->direction = direction;
	this->rectbullet = rectbullet;
	this->damage = damage;
	life = true;
	speed = 0.1;
	//√рузим картинку дл€ пули
	bulletpicture.loadFromFile("images/bullet.png");
	//”станавливаем маску дл€ картинки
	bulletpicture.createMaskFromColor(Color(0, 0, 0));
	//√рузим спрайт и текстуру
	texture.loadFromImage(bulletpicture);
	sprite.setTexture(texture);
}

void Bullet::Update(float time, Bullet & bullet, Map & map) {

	// оллизи€ пули с картой, проходимс€ по карте циклами

	for (int i = bullet.rectbullet.top / 32; i < (bullet.rectbullet.top + bullet.rectbullet.height) / 32; i++) {
		for (int j = bullet.rectbullet.left / 32; j < (bullet.rectbullet.left + bullet.rectbullet.width) / 32; j++)
		{
			//≈сли сталкиваемс€ с камнем либо стеной, то пул€ удал€етс€

			if (map.map[i][j] == 1 || map.map[i][j] == 2)
			{
				bullet.life = false;
			}

		}
	}

	//ƒвижение пули в 4 направлени€ 1 - вправо, 2 - вверх, 3 - влево, 4- вниз

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

	//”станавливаем позицию спрайта пули

	bullet.sprite.setPosition(bullet.rectbullet.left, bullet.rectbullet.top);
}