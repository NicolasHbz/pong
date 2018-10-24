#include <SFML/Graphics.hpp>
#include "Paddle.hh"
#include "global.hh"
#include <iostream>
#include <SFML/Audio.hpp>

Paddle::Paddle(std::string initialPosition)
{
    buffer.loadFromFile("assets/sounds/paddle.wav");
    sound.setBuffer(buffer);
    this->initialPosition = initialPosition;
    paddle.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
    paddle.setFillColor(sf::Color::White);
    paddle.setOrigin(PADDLE_WIDTH / 2, PADDLE_HEIGHT / 2);
    if (initialPosition == "left") {
        pos.x = 10;
        pos.y = HEIGHT / 2;
    } else if (initialPosition == "right") {
        pos.x = WIDTH - 10;
        pos.y = HEIGHT / 2;
    }
}

Paddle::~Paddle()
{   
}

void Paddle::draw(sf::RenderWindow &window)
{
    paddle.setPosition(pos);
    window.draw(paddle);
    this->update();
}

void Paddle::update()
{
    if (initialPosition == "left") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            pos.y--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            pos.y++;
        }
    } else if (initialPosition == "right") {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            pos.y++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            pos.y--;
        }
    }
    if ((pos.y + PADDLE_HEIGHT / 2) >= HEIGHT) pos.y--;
    if ((pos.y - PADDLE_HEIGHT / 2) <= 0) pos.y++;
}

void Paddle::playSound() 
{
    sound.play();
}

