#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pole.h"
#include "Plansza.h"
#ifndef UNTITLED5_GAMEMANAGER_H
#define UNTITLED5_GAMEMANAGER_H

class GameManager
{
    Intro &intro;
    Score &score;
    Plansza &pln;
    int width;
    int height;

    enum GameState
    {
        INTRO,
        GAME,
        SCORE
    } state;
    void debug_changeState();

  public:
    GameManager(Intro &in, Score &sc, Plansza &pln);
    void draw(sf::RenderWindow &win, int width, int height);
    void handleEvent(sf::Event &event);
};

#endif //UNTITLED5_GAMEMANAGER_H