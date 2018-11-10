#include "AbstractScreen.hh"
#include "Game.hh"
#include "Menu.hh"
#include "GameOver.hh"
#include "ScreenFactory.hh"

using namespace std;

const string ScreenFactory::MENU = "menu";
const string ScreenFactory::GAME = "game";
const string ScreenFactory::GAME_OVER_LEFT = "game-over-left";
const string ScreenFactory::GAME_OVER_RIGHT = "game-over-right";

ScreenFactory::ScreenFactory()
{
}

ScreenFactory::~ScreenFactory()
{
}

AbstractScreen* ScreenFactory::create(const string& name)
{
    if(!name.compare(ScreenFactory::MENU)) {
        return new Menu();
    } else if (!name.compare(ScreenFactory::GAME)) {
        return new Game();
    } else if (!name.compare(ScreenFactory::GAME_OVER_LEFT)) {
        return new GameOver("left");
    } else if (!name.compare(ScreenFactory::GAME_OVER_RIGHT)) {
        return new GameOver("right");
    }
    return NULL;
}