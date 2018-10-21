#include <SFML/Graphics.hpp>
#include "global.hh"
#include "GameOver.hh"

GameOver::GameOver(std::string param)
{
    roboto.loadFromFile("assets/fonts/Roboto.ttf");
    text.setFont(roboto);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(100);
    text.setPosition(WIDTH / 10, HEIGHT / 2);
    if (param == "left")
        text.setString("Left player won the game !!!");
    if (param == "right")
        text.setString("Right player won the game !!!");
}

GameOver::~GameOver()
{
}

void GameOver::draw(sf::RenderWindow &window)
{
    window.draw(text);
}



