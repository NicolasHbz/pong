#include <SFML/Graphics.hpp>
#include "global.hh"
#include "Game.hh"
#include "AbstractScreen.hh"
#include "Menu.hh"
#include "GameOver.hh"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong !!!");
    window.setFramerateLimit(FRAMELIMIT);

	window.setMouseCursorVisible(false);

    Menu menu;
	Game game;
    GameOver gameOverLeft("left");
    GameOver gameOverRight("right");
    std::vector<AbstractScreen*> Screens(ScreensItems::count);
    
    Screens[mainMenuScreen] = &menu;
    Screens[gameScreen] = &game;
    Screens[leftGameOverScreen] = &gameOverLeft;
    Screens[rightGameOverScreen] = &gameOverRight;

    int screen = 0;
	while (screen != exitGame)
		screen = Screens[screen]->run(window);

	return EXIT_SUCCESS;
}
