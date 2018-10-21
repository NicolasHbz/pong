#include <SFML/Graphics.hpp>
#include "global.hh"
#include "ScoreManager.hh"
#include "GameOver.hh"

ScoreManager::ScoreManager()
{
    leftScore = 0;
    rightScore = 0;
    roboto.loadFromFile("assets/fonts/Roboto.ttf");
    scoreLeftText.setFont(roboto);
    scoreLeftText.setFillColor(sf::Color::White);
    scoreLeftText.setCharacterSize(50);
    scoreLeftText.setPosition(0 + WIDTH / 4, 5);
    scoreRightText.setFont(roboto);
    scoreRightText.setFillColor(sf::Color::White);
    scoreRightText.setPosition(WIDTH - WIDTH / 4, 5);
    scoreRightText.setCharacterSize(50);
    scoreRightText.setString(std::to_string(rightScore));
}

void ScoreManager::draw(sf::RenderWindow &window)
{
    scoreLeftText.setString(std::to_string(leftScore));
    scoreRightText.setString(std::to_string(rightScore));
    window.draw(scoreLeftText);
    window.draw(scoreRightText);
    if (leftScore == MAX_SCORE) {
        window.clear();
        GameOver gameOver("left");
        gameOver.draw(window);
    }
    if (rightScore == MAX_SCORE) {
        window.clear();
        GameOver gameOver("right");
        gameOver.draw(window);
    }
}

void ScoreManager::update(std::string scoreToUpdate)
{
    if(scoreToUpdate == "Left")
        this->setLeftScore(this->getLeftScore() + 1);
    if (scoreToUpdate == "Right")
        this->setRightScore(this->getRightScore() + 1);
}

ScoreManager &ScoreManager::GetInstance()
{
    static ScoreManager uniqueInstance;
    return uniqueInstance;
}

int ScoreManager::getLeftScore() const
{
    return this->leftScore;
}

int ScoreManager::getRightScore() const
{
    return this->rightScore;
}

void ScoreManager::setLeftScore(int score)
{
    this->leftScore = score;
}

void ScoreManager::setRightScore(int score)
{
    this->rightScore = score;
}

void ScoreManager::resetScore()
{
    this->leftScore = 0;
    this->rightScore = 0;
}

