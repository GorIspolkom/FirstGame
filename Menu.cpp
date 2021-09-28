#include "Menu.h"

void Menu::SmallMenu() {

	RenderWindow window(VideoMode(600, 400), "ArenaMenu");
	Text gamename, playtext, exittext;
	Font font;
	Image icon;
	icon.loadFromFile("images/Icon.png");
	window.setIcon(32, 32, icon.getPixelsPtr());

	//MenuClick - отвечает за нажатие на "кнопки"
	int MenuCLick = 0;

	//Подгружаем шрифт
	font.loadFromFile("font.ttf");

	//Настройка всех текстовых полей меню

	gamename.setCharacterSize(40);
	gamename.setFont(font);
	gamename.setString("Arena");
	gamename.setFillColor(Color::Black);
	gamename.setPosition(window.getSize().x / 2  - 50, window.getSize().y / 2 - 80);

	playtext.setCharacterSize(30);
	playtext.setFont(font);
	playtext.setString("Play");
	playtext.setFillColor(Color::Black);
	playtext.setPosition(window.getSize().x / 2 - 20, window.getSize().y / 2 );

	exittext.setCharacterSize(30);
	exittext.setFont(font);
	exittext.setString("Exit");
	exittext.setFillColor(Color::Black);
	exittext.setPosition(window.getSize().x / 2 - 20, window.getSize().y / 2 + 80);

	while (window.isOpen() && isMenu) {

		//Если пользователь нажал и попал своей мышкой на определенный прямоугольник MenuClick меня значение
		//1 - Ничего не делает, 2- играть, 3 - выйти из программы

		if (IntRect(gamename.getPosition().x, gamename.getPosition().y, 50, 50).contains(Mouse::getPosition(window))){ 
			MenuCLick = 1; 
		}
		else if (IntRect(playtext.getPosition().x, playtext.getPosition().y, 50, 50).contains(Mouse::getPosition(window))){ 
			MenuCLick = 2; 
		}
		else if (IntRect(exittext.getPosition().x, exittext.getPosition().y, 50, 50).contains(Mouse::getPosition(window))){ 
			MenuCLick = 3; 
		}
		
		//Обработка нажатия левой кнопки мыши

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (MenuCLick == 1) {

			}
			else if (MenuCLick == 2){
				isMenu = false;
				isGame = true;
				window.close();
			}
			else if (MenuCLick == 3) {
				isGame = false;
				isMenu = false;
				window.close();
			}

		}

		//Если нажали на крест, закрываем программу

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed) {
				window.close();
				isMenu = false;
				isGame = false;
			}
				
		}
		
		//Отрисовка меню на красном фоне

		window.clear(Color::Red);
		window.draw(gamename);
		window.draw(playtext);
		window.draw(exittext);
		window.display();
	}
}