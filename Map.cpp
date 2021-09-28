#include "Map.h"


void Map::DrawMap(RenderWindow& window) {

	//Картинка map_image отвечает за "тайлсет" карты

	Image map_image;
	map_image.loadFromFile("tilemap/map.png");
	Texture maps;
	maps.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(maps);

	//Проходимся циклами по массиву и устанавливаем картинки

	for (int i = 0; i < Map_height; i++)
		for (int j = 0; j < Map_weight; j++)
		{
			//Устанавливаем текструру прямоугольником - пол, где можно пройти

			if (map[i][j] == 0) {
				s_map.setTextureRect(IntRect(0, 0, 32, 32));
			} 

			//Устанавливаем текструру прямоугольником - камень, где нельзя пройти

			else if (map[i][j] == 2) {
				s_map.setTextureRect(IntRect(32, 0, 32, 32));
			}

			//Устанавливаем текструру прямоугольником - стену, где нельзя пройти

			else if ((map[i][j] == 1)) {
				s_map.setTextureRect(IntRect(64, 0, 32, 32));
			}

			//Задаем позицию спрайт *32 тк. размер тайла 32 на 32

			s_map.setPosition(j * 32, i * 32);

			//Отрисовка
			window.draw(s_map);
		}
}


