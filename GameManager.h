#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pole.h"
#include "Plansza.h"
#include "Score.h"
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
    void draw(sf::RenderWindow &win, int width, int height,sf::Event &event);
    void handleEvent(sf::Event &event);
    void handleMouse(sf::Event &event);
    void updateState(sf::Event &event);
};

#endif //UNTITLED5_GAMEMANAGER_H