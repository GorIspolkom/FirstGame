#include "SFML/Graphics.hpp"
#ifndef Camera_h
#define Camera_h
#pragma once

using namespace sf;

//����� ������, ���� camera - ���� ������, MoveCamera - ����� �������� ������ � ����������� �� ���������� ������

class Camera
{
public:
	View camera;
	Camera(){}
	void MoveCamera(float x, float y);
};

#endif 
