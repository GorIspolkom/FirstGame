#include "ShopAndInfoBar.h"

ShopAndInfoBar::ShopAndInfoBar() {

	//��� �������� ���������� ������ ������������� ���� � ��������� ��� ��������� �����

	font.loadFromFile("font.ttf");
	playerh.setFont(font);
	playerscore.setFont(font);

	playerh.setFillColor(Color::Red);
	playerscore.setFillColor(Color::Red);

	playerh.setCharacterSize(15);
	playerscore.setCharacterSize(15);

	playerh.setPosition(25, 25);
	playerscore.setPosition(25, 50);
}


void ShopAndInfoBar::ShowInfo(Player& player, RenderWindow& window, Camera & cam) {

	//������� ����� � ����������� � ���������� ������, ����� �� ������ ��� � ������ ������� ����

	playerh.setPosition(cam.camera.getCenter().x - 315, cam.camera.getCenter().y - 240);
	playerscore.setPosition(cam.camera.getCenter().x - 315, cam.camera.getCenter().y - 220);

	//���������� ��� ������ ������ � sfml

	std::ostringstream playerScore;
	std::ostringstream playerhp;

	playerScore << player.score;
	playerhp << player.hp;

	//���� ���������� ����� ��� �� ������ 0 ������� 0

	if (player.hp < 0 || player.score < 0) {
		playerh.setString("Player Hp: 0");
		playerscore.setString("Player Score : 0");
	}

	//������� �� � ����

	else {
		playerh.setString("Player Hp: " + playerhp.str());
		playerscore.setString("Player Score: " + playerScore.str());
	}
	
	//��������� �����

	window.draw(playerh);
	window.draw(playerscore);
}

void ShopAndInfoBar::Death(Player&player) {

	RenderWindow window(sf::VideoMode(400, 300), "ArenaResults");
	Text text;
	std::ostringstream playerscore;
	Image icon;
	icon.loadFromFile("images/Icon.png");
	window.setIcon(32, 32, icon.getPixelsPtr());

	//���������� ��� ����� ����� ���������

	playerscore << player.score;

	//��������� ���������� ����

	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(Color::Black);
	text.setPosition(window.getSize().x / 2 - 110, window.getSize().y / 2 - 25);
	text.setString("Your score :" + playerscore.str());


	while (window.isOpen())
	{
	
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
		}

		//���������

		window.clear(Color::Red);
		window.draw(text);
		window.display();
		
	}
}