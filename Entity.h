#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef Entity_h
#define Entity_h
#pragma once

using namespace sf;

/* ласс существ, содержит пол€ имени, хп, пр€моугольника, картинки, текстуры, спрайта.
 онструктор имеет один параметр - им€, от которого завис€т все остальные параметры*/

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
