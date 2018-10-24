#include <SFML/Graphics.hpp>
#include "global.hh"
#include "GameOver.hh"
#include <iostream>

GameOver::GameOver(std::string param)
{
    if (param == "left")
        title.setString("Left player won the game !!!");
    if (param == "right")
        title.setString("Right player won the game !!!");
}

GameOver::~GameOver()
{
}

int GameOver::run(sf::RenderWindow &window)
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text playText;
	sf::Text exitText;
	int selectedMenuItem = 0;

    texture.loadFromFile("assets/images/background.png");
    sprite.setScale(sf::Vector2f(WIDTH / texture.getSize().x, HEIGHT / texture.getSize().y));
	sprite.setTexture(texture);

    font.loadFromFile("assets/fonts/Roboto.ttf");

    title.setFont(font);
    title.setFillColor(sf::Color::White);
    title.setCharacterSize(70);
    title.setPosition({ WIDTH / 5, 100 });

	playText.setFont(font);
	playText.setCharacterSize(50);
	playText.setString("New game");
	playText.setPosition({ WIDTH / 2.35f, 350 });

	exitText.setFont(font);
	exitText.setCharacterSize(50);
	exitText.setString("Exit");
	exitText.setPosition({ WIDTH / 2.1f, 450 });

	while (true)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return -1;
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
					case sf::Keyboard::Up:
						selectedMenuItem = play;
						break;
					case sf::Keyboard::Down:
						selectedMenuItem = exit;
						break;
					case sf::Keyboard::Return:
						if (selectedMenuItem == play) {
							return gameScreen;
						}
						else {
							return exitGame;
						}
						break;
					case sf::Keyboard::Escape:
						return exitGame;
						break;
					default:
						break;
				}
			}
		}

		if (selectedMenuItem == play) {
			playText.setFillColor(sf::Color::Red);
			exitText.setFillColor(sf::Color::White);
		}
		else if (selectedMenuItem == exit) {
			playText.setFillColor(sf::Color::White);
			exitText.setFillColor(sf::Color::Red);
		}

		window.clear();
		window.draw(sprite);
        window.draw(title);
		window.draw(playText);
		window.draw(exitText);
		window.display();
	}
	return -1;
}




