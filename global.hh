#ifndef _GLOBAL_HH
#define _GLOBAL_HH

// window
const float WIDTH = 1500.0f;
const float HEIGHT = WIDTH / 16.0f * 9.0f;
const int FRAMELIMIT = 400;

// paddle
const float PADDLE_WIDTH = 10;
const float PADDLE_HEIGHT = HEIGHT * 0.15f;

// game
const int MAX_SCORE = 3;
enum ScreensItems{
    exitGame = -1,
    mainMenuScreen = 0,
    gameScreen = 1,
    leftGameOverScreen = 2,
    rightGameOverScreen = 3,
    count = 4
};

#endif