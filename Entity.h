#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef Entity_h
#define Entity_h
#pragma once

using namespace sf;

/*����� �������, �������� ���� �����, ��, ��������������, ��������, ��������, �������.
����������� ����� ���� �������� - ���, �� �������� ������� ��� ��������� ���������*/

class Entity
{
public:
	std::string name;
	int hp;
	FloatRect rect;
	Image image;
	Texture texture;
	Sprite sprite;
	Entity(){}
	Entity(std::string name);
};

#endif 
