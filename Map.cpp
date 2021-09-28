#include "Map.h"


void Map::DrawMap(RenderWindow& window) {

	//�������� map_image �������� �� "�������" �����

	Image map_image;
	map_image.loadFromFile("tilemap/map.png");
	Texture maps;
	maps.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(maps);

	//���������� ������� �� ������� � ������������� ��������

	for (int i = 0; i < Map_height; i++)
		for (int j = 0; j < Map_weight; j++)
		{
			//������������� ��������� ��������������� - ���, ��� ����� ������

			if (map[i][j] == 0) {
				s_map.setTextureRect(IntRect(0, 0, 32, 32));
			} 

			//������������� ��������� ��������������� - ������, ��� ������ ������

			else if (map[i][j] == 2) {
				s_map.setTextureRect(IntRect(32, 0, 32, 32));
			}

			//������������� ��������� ��������������� - �����, ��� ������ ������

			else if ((map[i][j] == 1)) {
				s_map.setTextureRect(IntRect(64, 0, 32, 32));
			}

			//������ ������� ������ *32 ��. ������ ����� 32 �� 32

			s_map.setPosition(j * 32, i * 32);

			//���������
			window.draw(s_map);
		}
}


