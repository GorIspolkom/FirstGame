#include "SFML/Graphics.hpp"
#ifndef Camera_h
#define Camera_h
#pragma once

using namespace sf;

//Класс камеры, поле camera - сама камера, MoveCamera - метод движения камеры в зависимости от координаты игрока

class Camera
{
public:
	View camera;
	Camera(){}
	void MoveCamera(float x, float y);
};

#endif 
