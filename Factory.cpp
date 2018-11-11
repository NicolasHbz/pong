#include "AbstractScreen.hh"
#include "Game.hh"
#include "Menu.hh"
#include "GameOver.hh"
#include "Factory.hh"

using namespace std;

const string Factory::MENU = "menu";
const string Factory::GAME = "game";
const string Factory::GAME_OVER_LEFT = "game-over-left";
const string Factory::GAME_OVER_RIGHT = "game-over-right";
const string Factory::LEATHER_TEETH = "leather-teeth";
const string Factory::END_TITLES = "end-titles";

Factory::Factory()
{
}

Factory::~Factory()
{
}

AbstractScreen* Factory::createScreen(const string& name)
{
    if(!name.compare(Factory::MENU)) {
        return new Menu();
    } else if (!name.compare(Factory::GAME)) {
        return new Game();
    } else if (!name.compare(Factory::GAME_OVER_LEFT)) {
        return new GameOver("left");
    } else if (!name.compare(Factory::GAME_OVER_RIGHT)) {
        return new GameOver("right");
    }
    return NULL;
}

void Factory::getMusic(const string& songName)
{
    if(!songName.compare(Factory::LEATHER_TEETH)) {
        music.openFromFile("assets/music/Leather_teeth.wav");
    } else if(!songName.compare(Factory::END_TITLES)) {
        music.openFromFile("assets/music/End_Titles.wav");
    }
    music.setVolume(25);
    music.setLoop(true);
    music.play();
}

sf::Font& Factory::getFont()
{
    static sf::Font font;
    font.loadFromFile("assets/fonts/Roboto.ttf");
    return font;
}

sf::Texture Factory::getTexture()
{
    static sf::Texture texture;
    texture.loadFromFile("assets/images/background.png");
    return texture;
}

