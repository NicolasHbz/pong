#include <iostream>
#include "AbstractScreen.hh"

#include <SFML/Graphics.hpp>

class Menu : public AbstractScreen
{
private:
	bool playing;
	enum actions{ play = 0, exit = 1 };
public:
	Menu();
	~Menu();
	virtual int run(sf::RenderWindow &window);
};