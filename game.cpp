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
            leftPaddle.playSound();
            ball.direction.x *= -1.1;
    }
    if ((ball.pos.y < rightPaddle.pos.y + PADDLE_HEIGHT / 2)
        && (ball.pos.y > rightPaddle.pos.y - PADDLE_HEIGHT / 2)
        && (ball.pos.x > WIDTH - 15)) {
            rightPaddle.playSound();
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
    sf::Clock clock;
    sf::Font roboto;
    sf::Text fpsCounter;
    ScoreManager &scoreManager = ScoreManager::GetInstance();

    roboto.loadFromFile("assets/fonts/Roboto.ttf");
    fpsCounter.setFont(roboto);
    fpsCounter.setFillColor(sf::Color::Red);
    fpsCounter.setCharacterSize(25);
    fpsCounter.setPosition({ 15, 15 });

    sf::Texture bgTexture;
    bgTexture.loadFromFile("assets/images/background.png");
    sf::Sprite bgSprite;
    bgSprite.setScale(sf::Vector2f(WIDTH / bgTexture.getSize().x, HEIGHT / bgTexture.getSize().y));
    bgSprite.setTexture(bgTexture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				return exitGame;
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        return mainMenuScreen;
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

        sf::Time time = clock.getElapsedTime();
        window.draw(fpsCounter);
        fpsCounter.setString(std::to_string(int(1 / time.asSeconds())));
        clock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            ball.stopped = false;
        if (!ball.stopped)
            ball.update();

        scoreManager.draw(window);
        if (scoreManager.getLeftScore() == MAX_SCORE) {
            scoreManager.resetScore();
            return leftGameOverScreen;
        }
        else if (scoreManager.getRightScore() == MAX_SCORE) {
            scoreManager.resetScore();
            return rightGameOverScreen;
        }

        window.display();
    }
    return 0;
}