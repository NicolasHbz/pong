#include <SFML/Graphics.hpp>
#include "global.hh"
#include "Game.hh"
#include "AbstractScreen.hh"
#include "Menu.hh"
#include "GameOver.hh"
#include "ScreenFactory.hh"

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong !!!");
    window.setFramerateLimit(FRAMELIMIT);

	window.setMouseCursorVisible(false);

    ScreenFactory screenFactory;
    AbstractScreen *menu = screenFactory.create("menu");
	AbstractScreen *game = screenFactory.create("game");
    AbstractScreen *gameOverLeft = screenFactory.create("game-over-left");
    AbstractScreen *gameOverRight = screenFactory.create("game-over-right");

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
