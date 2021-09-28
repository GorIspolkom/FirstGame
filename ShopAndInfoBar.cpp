#include "ShopAndInfoBar.h"

ShopAndInfoBar::ShopAndInfoBar() {

	//При создании экземпляра класса устанавливаем шриф и настройки для текстовых полей

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

	//Двигаем текст в соответсвии с положением камеры, чтобы он всегда был в правом верхнем углу

	playerh.setPosition(cam.camera.getCenter().x - 315, cam.camera.getCenter().y - 240);
	playerscore.setPosition(cam.camera.getCenter().x - 315, cam.camera.getCenter().y - 220);

	//Переменные для вывода текста в sfml

	std::ostringstream playerScore;
	std::ostringstream playerhp;

	playerScore << player.score;
	playerhp << player.hp;

	//Если количество очков или хп меньше 0 выводим 0

	if (player.hp < 0 || player.score < 0) {
		playerh.setString("Player Hp: 0");
		playerscore.setString("Player Score : 0");
	}

	//Выводим хп и очки

	else {
		playerh.setString("Player Hp: " + playerhp.str());
		playerscore.setString("Player Score: " + playerScore.str());
	}
	
	//Отрисовка текса

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

	//Переменная для вывод очков персонажа

	playerscore << player.score;

	//Настройка текстового поля

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

		//Отрисовка

		window.clear(Color::Red);
		window.draw(text);
		window.display();
		
	}
}