#ifndef _GAME_OVER_HH
#define _GAME_OVER_HH

#include <SFML/Graphics.hpp>
#include "AbstractScreen.hh"

class GameOver: public AbstractScreen
{
    public:
	    enum actions{ play = 0, exit = 1 };
        std::string winner;

        GameOver(std::string param);
        ~GameOver();
        void draw(sf::RenderWindow &window);
        virtual int run(sf::RenderWindow &window);
};

#endif
