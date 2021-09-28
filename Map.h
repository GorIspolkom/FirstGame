#include <SFML/Graphics.hpp>
#ifndef Map_h
#define Map_h
#pragma once

using namespace sf;

/*����� �����, ����� �������� �������� 20 x 20, 0 - ���, ��� ����� ������, 1 - �����, ������ ������,
2 - ������, ������ ������, Map_weight, Map_height - ����������� �������, ����� DrawMap - ��������� ��� �������� 
�����, �� ������� �������� �����*/

class Map
{
public:
	static int const Map_weight = 20;
	static int const Map_height = 20;
	int map[Map_height][Map_weight] = {
  // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//0
	{1,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//1
	{1,2,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,1},//2
	{1,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1},//3
	{1,0,0,0,2,0,0,2,0,0,0,0,0,0,0,2,2,2,2,1},//4
	{1,0,0,0,2,2,0,2,0,0,0,0,0,0,0,2,0,0,0,1},//5
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1},//6
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1},//7
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1},//8
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//9
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//10
	{1,2,0,2,2,0,0,0,0,0,0,0,0,0,0,0,2,2,0,1},//11
	{1,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,1},//12
	{1,0,0,0,2,0,2,2,2,2,0,0,0,0,0,2,2,0,0,1},//13
	{1,0,0,0,2,0,2,0,0,2,0,0,0,0,0,2,0,0,0,1},//14
	{1,2,2,0,2,0,2,0,0,2,0,0,0,0,0,2,0,0,2,1},//15
	{1,0,0,0,0,0,2,0,0,0,0,0,2,2,2,0,0,0,0,1},//16
	{1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},//17
	{1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,1},//18
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//19
	};
	void DrawMap(RenderWindow& window);
};

#endif 