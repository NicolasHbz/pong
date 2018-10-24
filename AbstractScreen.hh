#ifndef _ABSTRACT_SCREEN_
#define _ABSTRACT_SCREEN_

#include <SFML/Graphics.hpp>

class AbstractScreen
{
    public:
        virtual ~AbstractScreen();
        virtual int run (sf::RenderWindow &window) = 0;

    protected:
        AbstractScreen();
};

#endif