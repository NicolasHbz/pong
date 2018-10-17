#include <SFML/Graphics.hpp>
#include <iostream>
#include "stdio.h"
#include "global.hh"
#include "Paddle.hh"
#include "Ball.hh"
#include "ScoreManager.hh"

void collision(Ball &ball, Paddle &leftPaddle, Paddle &rightPaddle, ScoreManager &scoreManager)
{
    if ((ball.pos.y < leftPaddle.pos.y + PADDLE_HEIGHT / 2)
        && (ball.pos.y > leftPaddle.pos.y - PADDLE_HEIGHT / 2)
        && (ball.pos.x < 10)) {
            ball.direction.x *= -1.1;
    }
    if ((ball.pos.y < rightPaddle.pos.y + PADDLE_HEIGHT / 2)
        && (ball.pos.y > rightPaddle.pos.y - PADDLE_HEIGHT / 2)
        && (ball.pos.x > WIDTH - 15)) {
            ball.direction.x *= -1.1;
    }
    if (ball.pos.x < 0) {
        scoreManager.setRightScore(scoreManager.getRightScore() + 1);
        ball.direction.x = -1;
        ball.resetPosition();
    }
    if (ball.pos.x > WIDTH) {
        ball.direction.x = 1;
        scoreManager.setLeftScore(scoreManager.getLeftScore() + 1);
        ball.resetPosition();
    }
}

void game()
{
    Paddle leftPaddle("left");
    Paddle rightPaddle("right");
    Ball ball;

    ScoreManager &scoreManager = ScoreManager::GetInstance();

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong !!!");
    window.setFramerateLimit(FRAMELIMIT);
    
    sf::Font roboto;
    roboto.loadFromFile("assets/fonts/Roboto.ttf");

    sf::Text scoreLeft;
    sf::Text scoreRight;
    scoreLeft.setFont(roboto);
    scoreLeft.setFillColor(sf::Color::White);
    scoreLeft.setPosition(0 + WIDTH / 4, 5);
    scoreLeft.setCharacterSize(50);
    scoreRight.setFont(roboto);
    scoreRight.setFillColor(sf::Color::White);
    scoreRight.setPosition(WIDTH - WIDTH / 4, 5);
    scoreRight.setCharacterSize(50);

    sf::Texture bgTexture;
    bgTexture.loadFromFile("assets/images/background.png");
    sf::Sprite bgSprite;
    bgSprite.setScale(sf::Vector2f(WIDTH / bgTexture.getSize().x, HEIGHT / bgTexture.getSize().y));
    bgSprite.setTexture(bgTexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) window.close();

        window.clear();
        window.draw(bgSprite);
        collision(ball, leftPaddle, rightPaddle, scoreManager);
        leftPaddle.draw(window);
        rightPaddle.draw(window);
        ball.draw(window);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) ball.stopped = false;
        if(!ball.stopped) ball.update();
        scoreLeft.setString(std::to_string(scoreManager.getLeftScore()));
        window.draw(scoreLeft);
        scoreRight.setString(std::to_string(scoreManager.getRightScore()));
        window.draw(scoreRight);
        window.display();
    }
}