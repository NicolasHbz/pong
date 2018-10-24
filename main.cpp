#include <SFML/Graphics.hpp>
#include "global.hh"
#include "Game.hh"
#include "AbstractScreen.hh"
#include "Menu.hh"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong !!!");
    window.setFramerateLimit(FRAMELIMIT);

	window.setMouseCursorVisible(false);

    Menu menu;
	Game game;
    std::vector<AbstractScreen*> Screens;
    Screens.push_back(&menu);
	Screens.push_back(&game);

    int screen = 0;
	while (screen >= 0)
	{
		screen = Screens[screen]->run(window);
	}

	return EXIT_SUCCESS;
}