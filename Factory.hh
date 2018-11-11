#ifndef _FACTORY_HH
#define _FACTORY_HH

#include <iostream>
#include <SFML/Audio.hpp>
#include "AbstractScreen.hh"

using namespace std;

class Factory
{
    public:
        Factory();
        ~Factory();
        sf::Music music;
        static AbstractScreen* createScreen(const string& name);
        void getMusic(const string& songName);
        static sf::Font& getFont();
        static sf::Texture getTexture();
        static const string MENU;
        static const string GAME;
        static const string GAME_OVER_LEFT;
        static const string GAME_OVER_RIGHT;
        static const string LEATHER_TEETH;
        static const string END_TITLES;
};

#endif