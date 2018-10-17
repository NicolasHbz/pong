#include "ScoreManager.hh"

ScoreManager::ScoreManager()
{
    leftScore = 0;
    rightScore = 0;
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
