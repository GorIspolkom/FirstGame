#include "EntityWalk.h"

EntityWalk::EntityWalk(std::string name) : Entity(name){

	//ѕрисваивание значений скорости в зависимости от значени€ переменной name

	this->name = name;

	if (name == "Player"){
		dx = 0.05;
		dy = 0.05;
	}
	else if (name == "Ghost") {
		dx = 0.025;
		dy = 0.025;
	}
	else if (name == "Tikva") {
		dx = 0.05;
		dy = 0.05;
	}
	else if (name == "BossLight") {
		dx = 0.05;
		dy = 0.05;
	}
	else if (name == "BossHard") {
		dx = 0.05;
		dy = 0.05;
	}
}

void EntityWalk::AnimationWalk(EntityWalk& walk, float time, float CurrentFrame) {
	
	//јнимаци€ ходьбы, если идем вверх, грузим картинку с героем, идущим вверх

	if (walk.dy<0) {
		if (CurrentFrame > 0.008 && walk.name!= "PlayerUp") {
			walk.image.loadFromFile("images/" + walk.name + "-TopAnim.png");
			CurrentFrame -= 0.08;
		}
		else {
			walk.image.loadFromFile("images/" + walk.name + "-Top.png");
		}
	}
	else if (walk.dx>0) {
		if (CurrentFrame > 0.008 && walk.name != "PlayerUp") {
			walk.image.loadFromFile("images/" + walk.name + "-RightAnim.png");
			CurrentFrame -= 0.08;
		}
		else {
			walk.image.loadFromFile("images/" + walk.name + "-Right.png");
		}
	}
	else if (walk.dy>0) {
		if (CurrentFrame > 0.008 && walk.name != "PlayerUp") {
			walk.image.loadFromFile("images/" + walk.name + "-DownAnim.png");
			CurrentFrame -= 0.08;
		}
		else {
			walk.image.loadFromFile("images/" + walk.name + "-Down.png");
		}
		
	}
	else if (walk.dx < 0) {
		walk.image.loadFromFile("images/" + walk.name + "-Left.png");
		if (CurrentFrame > 0.008 && walk.name != "PlayerUp") {
			walk.image.loadFromFile("images/" + walk.name + "-LeftAnim.png");
			CurrentFrame -= 0.08;
		}
	}
	else {
		walk.image.loadFromFile("images/" + walk.name + "-Down.png");
	}
	walk.texture.loadFromImage(image);
	walk.sprite.setTexture(texture);
}


void EntityWalk::CollisionWithMap(EntityWalk& walk, Map & map) {

	/*ќбработка столкновени€ с картой, проходимс€ по карте вложенным циклом
	если столкновение с камнем или стеной срабатывает условие, в зависимости от направлени€ движени€*/

	for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++) {
		for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
		{
			if (map.map[i][j] == 1 || map.map[i][j] == 2)
			{
				if (dx > 0) {
					rect.left = j * 32 - rect.width;
				}
				else if (dx < 0) {
					rect.left = j * 32 + 32;
				}
				else if (dy > 0) {
					rect.top = i * 32 - rect.height;
				}
				else if (dy < 0) {
					rect.top = i * 32 + 32;
				}
			}

		}
	}
}


void EntityWalk::Update(float time, EntityWalk& walk, Map & map, float CurrentFrame) {

	//ѕолучаем координаты существа

	walk.x = round((int)walk.sprite.getPosition().x / 32);
	walk.y = round((int)walk.sprite.getPosition().y / 32);

	//”станавливаем значение пр€моугольника в зависимости от времени и скорости

	rect.left += dx * time;
	rect.top += dy * time;

	//ќбработка столкновени€ с картой

	CollisionWithMap(walk, map);

	//”станавливаем новую позицию дл€ спрайт

	walk.sprite.setPosition(rect.left, rect.top);

	//јнимаци€ ходьбы и зануление скоростей

	AnimationWalk(walk, time, CurrentFrame);
	dx = 0;
	dy = 0;
}

