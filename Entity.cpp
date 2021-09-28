#include "Entity.h"

Entity::Entity(std::string name) {

	//����������� ���������� ����� �������� ��������� ������������

	this->name = name;

	//������������ ���������� � ����������� �� �������� name

	if (name == "Player") {
		hp = 100;
		rect = FloatRect(150, 150, 26, 32);
	}
	else if (name == "Ghost") {
		hp = 10;
		rect = FloatRect(100, 50, 29, 32);
	}
	else if (name == "Tikva") {
		hp = 20;
		rect = FloatRect(48, 48, 25, 32);
	}
	else if (name == "BossLight") {
		hp = 100;
		rect = FloatRect(48, 48, 65, 80);
	}
	else if (name == "BossHard"){
		hp = 200;
		rect = FloatRect(48, 48, 97, 98);
	}

	//������ �������� � ������������� ������

	image.loadFromFile("images/"+ name + "-Down.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}


