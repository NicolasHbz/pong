#include <SFML/Graphics.hpp>
#include <iostream>
#include "stdio.h"
#include "global.hh"
#include "Paddle.hh"
#include "Ball.hh"
#include "ScoreManager.hh"
#include "Game.hh"

Game::Game(){}

Game::~Game(){}

void Game::collision(Ball &ball, Paddle &leftPaddle, Paddle &rightPaddle, ScoreManager &scoreManager)
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
        scoreManager.update("Right");
        ball.direction.x = -1;
        ball.resetPosition();
    }
    if (ball.pos.x > WIDTH) {
        ball.direction.x = 1;
        scoreManager.update("Left");
        ball.resetPosition();
    }
}

int Game::run(sf::RenderWindow &window)
{
    Paddle leftPaddle("left");
    Paddle rightPaddle("right");
    Ball ball;
    ScoreManager &scoreManager = ScoreManager::GetInstance();

    sf::Texture bgTexture;
    bgTexture.loadFromFile("assets/images/background.png");
    sf::Sprite bgSprite;
    bgSprite.setScale(sf::Vector2f(WIDTH / bgTexture.getSize().x, HEIGHT / bgTexture.getSize().y));
    bgSprite.setTexture(bgTexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				return -1;
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
                    case sf::Keyboard::Escape:
                        return 0;
                        break;
                    default:
                        break;
				}
			}
		}

        window.clear();
        window.draw(bgSprite);
        collision(ball, leftPaddle, rightPaddle, scoreManager);
        leftPaddle.draw(window);
        rightPaddle.draw(window);
        ball.draw(window);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) ball.stopped = false;
        if(!ball.stopped) ball.update();
        scoreManager.draw(window);
        window.display();
    }
    return -1;
}