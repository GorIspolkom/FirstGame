#include "PlayerController.h"

void PlayerController::Update(float time, Player& player, float CurrentFrame, Camera & cam, Map & map) {

	//Обновление текущего кадра
	CurrentFrame += 0.05 * time;

	//Условие на стрельбу и ее скорость


	if (player.guntime <= 5) {
		player.guntime += player.gunrange;
	}

	//Управление персонажем на WASD

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

	//Покупка улучшений на G

	else if (Keyboard::isKeyPressed(Keyboard::G)) {
		player.Upgrade(player);
	}

	//Стрельба на стрелочки, добавляем в вектор пуль новый элемент пули, обнуляем время стрельбы, увеличиваем количество пуль

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

	//Двигаем камеру в зависимости от положения персонажа

	cam.MoveCamera(player.sprite.getPosition().x, player.sprite.getPosition().y);

	//Проходимся циклом по элементам вектора пуль

	for (int i = 0; i < player.bulletsnum; i++) {

		//Если пуля жива, то вызываем для каждой метод Update

		if (player.bullets[i]->life) {
			player.bullets[i]->Update(time, *player.bullets[i], map);
		}

		//Удаляем обьект пули, удаляем элемент пули из списка и уменьшаем количество пуль

		else {
			delete player.bullets[i];
			player.bullets.erase(player.bullets.cbegin() + i);
			player.bulletsnum--;
		}
	}

	//Вызываем Update игрока

	player.Update(time, player, map, CurrentFrame);
}