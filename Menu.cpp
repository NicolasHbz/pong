#include "Menu.hh"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "global.hh"
#include "Factory.hh"

Menu::Menu()
{
	playing = false;
}

Menu::~Menu(){}

int Menu::run(sf::RenderWindow &window)
{
	bool running = true;
	sf::Sprite sprite;
	sf::Text playText;
	sf::Text exitText;
	sf::Text continueText;
	int selectedMenuItem = 0;
    Factory factory;

    sf::Texture texture = Factory::getTexture();
    sprite.setScale(sf::Vector2f(WIDTH / texture.getSize().x, HEIGHT / texture.getSize().y));
	sprite.setTexture(texture);

	playText.setFont(Factory::getFont());
	playText.setCharacterSize(70);
	playText.setString("Play");
	playText.setPosition({ WIDTH / 7, 250 });

	exitText.setFont(Factory::getFont());
	exitText.setCharacterSize(70);
	exitText.setString("Exit");
	exitText.setPosition({ WIDTH / 7, 450 });

	continueText.setFont(Factory::getFont());
	continueText.setCharacterSize(70);
	continueText.setString("Continue");
	continueText.setPosition({ WIDTH / 7, 250 });

    factory.getMusic(factory.END_TITLES);

	while (running)
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
							playing = true;
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
			continueText.setFillColor(sf::Color::Red);
		}
		else if (selectedMenuItem == exit) {
			playText.setFillColor(sf::Color::White);
			exitText.setFillColor(sf::Color::Red);
			continueText.setFillColor(sf::Color::White);
		}

		window.clear();
		window.draw(sprite);

		if (playing)
			window.draw(continueText);
		else
			window.draw(playText);

		window.draw(exitText);
		window.display();
	}
	return exitGame;
}
