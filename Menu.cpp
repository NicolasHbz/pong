#include "Menu.hh"
#include <SFML/Graphics.hpp>
#include "global.hh"

Menu::Menu(void)
{
	playing = false;
}

Menu::~Menu(){}

int Menu::run(sf::RenderWindow &window)
{
	bool running = true;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Font font;
	sf::Text playText;
	sf::Text exitText;
	sf::Text continueText;
	int selectedMenuItem = 0;

    texture.loadFromFile("assets/images/background.png");
    sprite.setScale(sf::Vector2f(WIDTH / texture.getSize().x, HEIGHT / texture.getSize().y));
	sprite.setTexture(texture);

	font.loadFromFile("assets/fonts/Roboto.ttf");
	playText.setFont(font);
	playText.setCharacterSize(70);
	playText.setString("Play");
	playText.setPosition({ WIDTH / 7, 250 });

	exitText.setFont(font);
	exitText.setCharacterSize(70);
	exitText.setString("Exit");
	exitText.setPosition({ WIDTH / 7, 450 });

	continueText.setFont(font);
	continueText.setCharacterSize(70);
	continueText.setString("Continue");
	continueText.setPosition({ WIDTH / 7, 250 });

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
							return 1;
						}
						else {
							return -1;
						}
						break;
					case sf::Keyboard::Escape:
						return -1;
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
	return -1;
}
