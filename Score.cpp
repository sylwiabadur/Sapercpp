#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Pole.h"
#include "Plansza.h"
#include "Intro.h"
#include "Score.h"

Score::Score()
{
    height = 600;
    width = 600;
    rect.setSize(sf::Vector2f(height, width));
    rect.setPosition(0, 0);
}

void Score::draw(sf::RenderWindow &win)
{
    sf::Text text;
    sf::Text text1;
    sf::Text text2;
    text.setFont(Plansza::font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(width * 0.2, height * 0.4);
    text1.setFont(Plansza::font);
    text1.setCharacterSize(20);
    text1.setFillColor(sf::Color::Blue);
    text1.setPosition(width * 0.3, height * 0.45);
    text2.setFont(Plansza::font);
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::Blue);
    text2.setPosition(width * 0.35, height * 0.45);
    text1.setString(std::to_string(Plansza::licznikRuchow));
    text2.setString("MOVES");
    if (Plansza::wygrana)
    {
        text.setString("END OF THE GAME. YOU WON AFTER");
    }
    else text.setString("END OF THE GAME. YOU LOST AFTER");
    
    win.draw(rect);
    win.draw(text);
    win.draw(text1);
    win.draw(text2);
}