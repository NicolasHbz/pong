#include <iostream>
#include "AbstractScreen.hh"
#include <SFML/Graphics.hpp>

class Menu : public AbstractScreen
{
    private:
        bool playing;
        enum actions{ play = 0, exit = 1 };
        sf::Text title;

    public:
        Menu();
        ~Menu();
        virtual int run(sf::RenderWindow &window) override;
        void notify(std::string winner) override;
};