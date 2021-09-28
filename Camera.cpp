#include "Camera.h"

void Camera::MoveCamera(float x, float y) {

	//ѕолучаем значение переменных дл€ камеры

	float mapx = x; 
	float mapy = y;

	//”слови€ дл€ изменени€ координат камеры

	if (x < 320)
	{
		mapx = 320;

	}
	if (x > 962) {

		mapx = 962;

	}
	if (y < 240) {

		mapy = 240; 

	}
	if (y > 554) { 

		mapy = 554;

	}

	//÷ентрируем камеру на координаты переменных

	camera.setCenter(mapx, mapy);
}