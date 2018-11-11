#ifndef _SCORE_MANAGER_HH
#define _SCORE_MANAGER_HH

#include <SFML/Graphics.hpp>
#include "AbstractEntity.hh"

class ScoreManager
{
    private:
        ScoreManager();
        ScoreManager(const ScoreManager&) = delete;
        ScoreManager& operator=(const ScoreManager&) = delete;

    public:
        static ScoreManager &GetInstance();
        void setLeftScore(int score);
        void setRightScore(int score);
        int getLeftScore() const;
        int getRightScore() const;
        void resetScore();
        void draw(sf::RenderWindow &window);
        void update(std::string scoreToUpdate);
        sf::Text scoreLeftText;
        sf::Text scoreRightText;
        int leftScore;
        int rightScore;
};

#endif
