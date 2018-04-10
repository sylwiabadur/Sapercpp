#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pole.h"
#include "Plansza.h"
#ifndef UNTITLED5_SCORE_H
#define UNTITLED5_SCORE_H

class Score
{
  int width;
  int height;
  sf::RectangleShape rect;

  public:
    Score();
    void draw(sf::RenderWindow &win);
    bool handleEvent(sf::Event &event);
};
#endif //UNTITLED5_SCORE_H