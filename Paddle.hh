#ifndef _PADDLE_HH
#define _PADDLE_HH

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AbstractEntity.hh"

class Paddle: public AbstractEntity
{
    public:
        Paddle(std::string initialPosition);
        ~Paddle();
        virtual void draw(sf::RenderWindow &window) override;
        virtual void update() override;
        void playSound();
        sf::RectangleShape paddle;
        std::string initialPosition;
        sf::SoundBuffer buffer;
        sf::Sound sound;

};

#endif 