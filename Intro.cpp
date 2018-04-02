#include <SFML/Graphics.hpp>
#include "Plansza.h"
#include "Pole.h"
#include "Intro.h"
#include <iostream>
Intro::Intro()
{
    height=600;
    width=600;
    rect.setSize(sf::Vector2f(height, width));
    rect.setPosition(0, 0);
}
void Intro::draw(sf::RenderWindow &win)
{
    sf::Text text;
    text.setFont(Plansza::font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(width*0.2,height*0.4);
    text.setString("WELCOME! PRESS SPACE TO START");
    win.draw(rect);
    win.draw(text);
}