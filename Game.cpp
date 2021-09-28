#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "MobsController.h"
#include "ShopAndInfoBar.h"
#include "Menu.h"

using namespace sf;

int main() {
	//Создаем экземпляр меню
	Menu menu;
	//Вызываем функцию отображения начального меню
	menu.SmallMenu();
	//Создание окна
	RenderWindow window(VideoMode(800, 600), "Arena");
	Image icon;
	icon.loadFromFile("images/Icon.png");
	window.setIcon(32, 32, icon.getPixelsPtr());
	//Создаем экземпляр игрока
	Player player("Player");
	//Создаем экземпляр панели для отображения
	ShopAndInfoBar bar;
	//Создаем обьект контроллера игрока
	PlayerController controll;
	//Создаем обьект времени
	Clock clock;
	//Создаем экземпляр карты
	Map map;
	//Создаем экземпляр карты
	Camera cam;
	//Создаем экземпляр контроллера мобов
	MobsController mobcotroll;
	//Устанавливаем значение для камеры
	cam.camera.reset(FloatRect(0, 0, 640, 480));
	//Для анимации
	float CurrentFrame = 0;

	while (window.isOpen() && menu.isGame && !menu.isMenu)
	{

		//Если мобов нет, то спавним их
		if (mobcotroll.mobcol==0) {
			//Спавн
			mobcotroll.SpawnMobs();
		}
		//Получаем время в микросекундах
		float time = clock.getElapsedTime().asMicroseconds();
		//Сбрасываем значение времени
		clock.restart();
		//Регулировка скорости игры
		time = time / 800;
		
		Event event;

		while (window.pollEvent(event))
		{
			
			if (event.type == Event::Closed)
				window.close();
		}
		if (player.hp > 0) {
			//Если игрок живой, то обновляем его
			controll.Update(time, player, CurrentFrame, cam, map);
		}
		else {
			//В ином случае закрываем окно и вызываем функцию смерти - вывод экрана с очками
			window.close();
			bar.Death(player);
		}
		//Контролим мобов 
		mobcotroll.MobContoll(player, time, map, CurrentFrame);
		//Устанавливаем камеру
		window.setView(cam.camera);
		//Очищаем окно
		window.clear(Color::Red);
		//Отрисовка карты
		map.DrawMap(window);
		
		//Отрисовка спрайтов всех мобов
		for (int i = 0; i < mobcotroll.mobcol; i++) {
			window.draw(mobcotroll.mobpool[i]->sprite);
		}
		//Отрисовка спрайтов всех пуль
		for (int i = 0; i < player.bulletsnum; i++) {
			window.draw(player.bullets[i]->sprite);
		}
		//Отрисовка спрайта игрока
		window.draw(player.sprite);
		//Обновляем информацию об игроке
		bar.ShowInfo(player, window, cam);
		//Рендерим все
		window.display();
        
	}

	return 0;
}

