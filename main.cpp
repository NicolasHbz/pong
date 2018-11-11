#include <SFML/Graphics.hpp>
#include "global.hh"
#include "Game.hh"
#include "AbstractScreen.hh"
#include "Menu.hh"
#include "GameOver.hh"
#include "Factory.hh"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong !!!");
    window.setFramerateLimit(FRAMELIMIT);

	window.setMouseCursorVisible(false);

    AbstractScreen *menu = Factory::createScreen("menu");
	AbstractScreen *game = Factory::createScreen("game");
    AbstractScreen *gameOverLeft = Factory::createScreen("game-over-left");
    AbstractScreen *gameOverRight = Factory::createScreen("game-over-right");

    std::vector<AbstractScreen*> Screens(ScreensItems::count);
    Screens[mainMenuScreen] = menu;
    Screens[gameScreen] = game;
    Screens[leftGameOverScreen] = gameOverLeft;
    Screens[rightGameOverScreen] = gameOverRight;

    int currentScreen = 0;
	while (currentScreen != exitGame)
		currentScreen = Screens[currentScreen]->run(window);

	return EXIT_SUCCESS;
}
