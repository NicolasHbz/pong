#ifndef _BALL_HH
#define _BALL_HH

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
        sf::SoundBuffer buffer;
        sf::Sound sound;
        sf::SoundBuffer bufferFalledBall;
        sf::Sound soundFalledBall;
};

#endif