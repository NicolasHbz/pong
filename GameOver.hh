#ifndef _GAME_OVER_HH
#define _GAME_OVER_HH

#include <SFML/Graphics.hpp>
#include "AbstractScreen.hh"

class GameOver: public AbstractScreen
{
    public:
        bool playing;
	    enum actions{ play = 0, exit = 1 };

        GameOver(std::string param);
        ~GameOver();
        void draw(sf::RenderWindow &window);
        sf::Text title;
        virtual int run(sf::RenderWindow &window);
};

#endif
