#include <SFML/Graphics.hpp>
#include "Pole.h"
#include "Plansza.h"
#include <iostream>
#ifndef UNTITLED5_INTRO_H
#define UNTITLED5_INTRO_H

class Intro
{
    sf::RectangleShape rect;
    int width;
    int height;

  public:
    Intro();
    void draw(sf::RenderWindow &win);
    bool handleEvent(sf::Event &event);
  };
  
#endif //UNTITLED5_INTRO_H