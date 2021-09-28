#include "MobsController.h"


void MobsController::MobContoll(Player& player, float time, Map& map, float CurrentFrame) {
	/*Вызываем Update для каждого моба и пули, если прямоугольник моба пересекся с игроком, то моб умирает, а
	игрок получается опредленых урон, если количество hp мобов 0 или меньше удаляем моба из списка, аналогично с пулей,
	при смерти моба с пули игрок получает очки, удаляем пулю при столкновении с мобом*/
	if (!mobpool.empty()) {
	for (int i = 0; i < mobcol; i++) {
		mobpool[i]->Update(player, time, *mobpool[i], map, CurrentFrame);
		if (mobpool[i]->rect.intersects(player.rect)) {
			player.hp -= mobpool[i]->damage;
			delete mobpool[i];
			mobpool.erase(mobpool.begin() + i);
			mobcol--;
		}
		for (int j = 0; j < player.bulletsnum; j++) {
			if (mobpool[i]->rect.intersects(player.bullets[j]->rectbullet)) {
				mobpool[i]->hp -= player.bullets[j]->damage;
				if (mobpool[i]->hp <= 0) {
					player.score += mobpool[i]->scoreperdeath;
					delete mobpool[i];
					mobpool.erase(mobpool.begin() + i);
					mobcol--;
				}
				delete player.bullets[j];
				player.bullets.erase(player.bullets.cbegin() + j);
				player.bulletsnum--;
			}
		}
	}
}
}


void MobsController::SpawnMobs() {
	//Спавн мобов
	
	//Увеличение количества волн
	colwoln++;
	//random
	srand(time(0));

	//Спавним определенных мобов в зависимости от волны

	if (colwoln > 10 && mobcol == 0) {

		mobcol = 4 + rand() % 12;

		for (int i = 0; i < mobcol; i++) {
			mobpool.push_back(new NonShootMob(Names[rand() % 2]));
			mobpool[i]->rect.left = spawncoord[rand() % 5].first * 32, mobpool[i]->rect.top = spawncoord[rand() % 5].second * 32;
			mobpool[i]->sprite.setPosition(mobpool[i]->rect.left, mobpool[i]->rect.top);
		}

	}
	else if (mobcol == 0 && colwoln % 10 == 0) {

		mobcol = 1;

		mobpool.push_back(new NonShootMob("BossHard"));
		mobpool[0]->rect.left = 400, mobpool[0]->rect.top = 400;
		mobpool[0]->sprite.setPosition(mobpool[0]->rect.left, mobpool[0]->rect.top);
	}
	else if (mobcol == 0 && colwoln%3!=0) {

		mobcol = 1 + rand() % 5;

		for (int i = 0; i < mobcol; i++) {
			mobpool.push_back(new NonShootMob(Names[rand() % 2]));
			mobpool[i]->rect.left = spawncoord[rand()%5].first * 32, mobpool[i]->rect.top = spawncoord[rand()%5].second * 32;
			mobpool[i]->sprite.setPosition(mobpool[i]->rect.left, mobpool[i]->rect.top);
		}
	}
	else if(mobcol==0 && colwoln%3==0){

		mobcol = 1;

		mobpool.push_back(new NonShootMob("BossLight"));
		mobpool[0]->rect.left = 300, mobpool[0]->rect.top = 300;
		mobpool[0]->sprite.setPosition(mobpool[0]->rect.left, mobpool[0]->rect.top);
	}
}

