#include <SFML/Graphics.hpp>
#ifndef Menu_h
#define Menu_h
#pragma once

using namespace sf;

class Menu
{
	/*����� ����, � ������� ������� main ��������� ��������� ������ � ���������� 
	����� SmallMenu, ������� �������� �� ����� ���� ����� �����, � ����� "��������" - ������ � �����*/
public:
	//isGame - �������� �� ��, ����� �� �������� ���� � ������� ��������� �������
	bool isGame = false;
	//isMenu - ������ ���� ��� ���
	bool isMenu = true;
	Menu(){}
	void SmallMenu();
};

#endif 