#include <SFML\Graphics\Image.hpp>
#include "Map.h"
#ifndef Bullet_h
#define Bullet_h
#pragma once

using namespace std;

/*����� ����, � ����������� ���������� �����������, ������������� ��� ����, ���� , ���� - ����� ����, ��������,
����� Update - ���������� ������ �����, �������� �� ��������� � ������������ ����*/

class Bullet
{
public:
	sf::Image bulletpicture;
	sf::FloatRect rectbullet;
	sf::Sprite sprite;
	sf::Texture texture;
	bool life;
	int damage;
	int direction;
	float speed;
	~Bullet(){}
	Bullet(int direction, FloatRect rectbullet, int damage);
	void Update(float time, Bullet& bullet, Map& map);
};

#endif 

