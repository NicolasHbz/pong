#ifndef _BALL_HH
#define _BALL_HH

#include <SFML/Graphics.hpp>
#include "AbstractEntity.hh"

class Ball : public AbstractEntity
{
    public:
        Ball();
        ~Ball();
        virtual void draw(sf::RenderWindow &window) override;
        virtual void update() override;
        void resetPosition();
        bool stopped;
        sf::CircleShape ball;
        sf::Vector2f direction;
};

#endif