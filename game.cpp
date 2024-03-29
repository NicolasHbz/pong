#include <SFML/Graphics.hpp>
#include <iostream>
#include "stdio.h"
#include "global.hh"
#include "Paddle.hh"
#include "Ball.hh"
#include "ScoreManager.hh"
#include "Game.hh"
#include "Factory.hh"

Game::Game(){}

Game::~Game(){}

void Game::addObserver(AbstractScreen* observer)
{
    this->observer = observer;
}

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
    sf::Time time;
    sf::Text fpsCounter, pause;
    ScoreManager &scoreManager = ScoreManager::GetInstance();
    Factory factory;
    bool paused = false;

    fpsCounter.setFont(Factory::getFont());
    fpsCounter.setFillColor(sf::Color::Red);
    fpsCounter.setCharacterSize(25);
    fpsCounter.setPosition({ 15, 15 });

    pause.setFont(Factory::getFont());
    pause.setFillColor(sf::Color::Red);
    pause.setCharacterSize(75);
    pause.setPosition({ WIDTH / 2.4f, HEIGHT / 2 });
    pause.setString("PAUSE");

    sf::Texture bgTexture = Factory::getTexture();
    sf::Sprite bgSprite;
    bgSprite.setScale(sf::Vector2f(WIDTH / bgTexture.getSize().x, HEIGHT / bgTexture.getSize().y));
    bgSprite.setTexture(bgTexture);

    factory.getMusic(factory.LEATHER_TEETH);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				return exitGame;
			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        paused = !paused;
                        break;
                    default:
                        break;
				}
			}
		}

        if (!paused) {
            window.clear();
            window.draw(bgSprite);
            leftPaddle.draw(window);
            rightPaddle.draw(window);
            ball.draw(window);
            window.draw(fpsCounter);
            scoreManager.draw(window);
            if (!ball.stopped)
                ball.update();
        } else {
            window.draw(pause);
        }

        collision(ball, leftPaddle, rightPaddle, scoreManager);

        time = clock.getElapsedTime();
        fpsCounter.setString(std::to_string(int(1 / time.asSeconds())));
        clock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            ball.stopped = false;

        if (scoreManager.getLeftScore() == MAX_SCORE) {
            scoreManager.resetScore();
            observer->notify("left");
            return mainMenuScreen;
        } else if (scoreManager.getRightScore() == MAX_SCORE) {
            scoreManager.resetScore();
            observer->notify("right");
            return mainMenuScreen;
        }

        window.display();
    }
    return 0;
}