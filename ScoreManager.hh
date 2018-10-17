#ifndef _SCORE_MANAGER_HH
#define _SCORE_MANAGER_HH

#include <SFML/Graphics.hpp>

class ScoreManager
{
    private:
        ScoreManager();
        ScoreManager(const ScoreManager&) = delete;
        ScoreManager& operator=(const ScoreManager&) = delete;
        int leftScore;
        int rightScore;

    public:
        static ScoreManager &GetInstance();
        void setLeftScore(int score);
        void setRightScore(int score);
        int getLeftScore() const;
        int getRightScore() const;
};

#endif
