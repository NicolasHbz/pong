#ifndef _ABSTRACT_ENTITY_HH
#define _ABSTRACT_ENTITY_HH

#include <SFML/Graphics.hpp>

class AbstractEntity {
    public:
        virtual ~AbstractEntity();
        virtual void draw(sf::RenderWindow &window) = 0;
        virtual void update() = 0;
        sf::Vector2f pos;

    protected:
        AbstractEntity();
    };

#endif