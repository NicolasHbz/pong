#ifndef _GAME_OVER_HH
#define _GAME_OVER_HH

#include <SFML/Graphics.hpp>

class GameOver
{
    public:
        GameOver(std::string param);
        ~GameOver();
        void draw(sf::RenderWindow &window);
        sf::Text text;
        sf::Font roboto;
};

#endif
