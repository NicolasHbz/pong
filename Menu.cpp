#include "Menu.hh"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "global.hh"
#include "Factory.hh"

Menu::Menu()
{
	playing = false;
}

Menu::~Menu()
{
}

void Menu::notify(std::string winner)
{
    title.setString("");

    if (winner == "left")
        title.setString("Left player won the game !!!");
    else if (winner == "right")
        title.setString("Right player won the game !!!");
}

int Menu::run(sf::RenderWindow &window)
{
	sf::Sprite sprite;
	sf::Text playText;
	sf::Text exitText;
	int selectedMenuItem = 0;
    Factory factory;

    sf::Texture texture = Factory::getTexture();
    sprite.setScale(sf::Vector2f(WIDTH / texture.getSize().x, HEIGHT / texture.getSize().y));
	sprite.setTexture(texture);

    title.setFont(Factory::getFont());
    title.setFillColor(sf::Color::Green);
    title.setCharacterSize(70);
    title.setPosition({ WIDTH / 5, 100 });

	playText.setFont(Factory::getFont());
	playText.setCharacterSize(70);
	playText.setString("Play");
	playText.setPosition({ WIDTH / 7, 350 });

	exitText.setFont(Factory::getFont());
	exitText.setCharacterSize(70);
	exitText.setString("Exit");
	exitText.setPosition({ WIDTH / 7, 450 });

    factory.getMusic(factory.END_TITLES);

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

        window.clear();

		if (selectedMenuItem == play) {
			playText.setFillColor(sf::Color::Red);
			exitText.setFillColor(sf::Color::White);
		}
		else if (selectedMenuItem == exit) {
			playText.setFillColor(sf::Color::White);
			exitText.setFillColor(sf::Color::Red);
		}

		window.draw(sprite);
		window.draw(playText);
        window.draw(title);
		window.draw(exitText);
		window.display();
	}
	return exitGame;
}
