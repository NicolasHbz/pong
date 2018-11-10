#ifndef _SCREEN_FACTORY_HH
#define _SCREEN_FACTORY_HH

#include <iostream>

#include "AbstractScreen.hh"

using namespace std;

class ScreenFactory
{
    public:
        ScreenFactory();
        ~ScreenFactory();
        AbstractScreen* create(const string& name);
        static const string MENU;
        static const string GAME;
        static const string GAME_OVER_LEFT;
        static const string GAME_OVER_RIGHT;
};

#endif