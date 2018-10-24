#include <SFML/Graphics.hpp>
#include "Ball.hh"
#include "global.hh"

Ball::Ball()
{
    buffer.loadFromFile("assets/sounds/ball.wav");
    sound.setBuffer(buffer);
    bufferFalledBall.loadFromFile("assets/sounds/ball_falled.wav");
    soundFalledBall.setBuffer(bufferFalledBall);
    ball.setRadius(5);
    ball.setFillColor(sf::Color::White);
    pos.x = WIDTH / 2;
    pos.y = HEIGHT / 2;
    direction.x = 1;
    direction.y = 1;
    stopped = true;
}

Ball::~Ball()
{
}

void Ball::draw(sf::RenderWindow &window)
{
    ball.setPosition(pos);
    window.draw(ball);
}

void Ball::update()
{
    pos.x += direction.x;
    pos.y += direction.y;
    if (pos.y <= 0 || pos.y >= HEIGHT) {
        sound.play();
        direction.y *= -1;
    }
}

void Ball::resetPosition()
{
    pos.x = WIDTH / 2;
    pos.y = HEIGHT / 2;
    stopped = true;
    soundFalledBall.play();
}