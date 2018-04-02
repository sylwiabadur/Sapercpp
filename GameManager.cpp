#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pole.h"
#include "Plansza.h"
#include "Intro.h"
#include "Score.h"
#include "GameManager.h"
GameManager::GameManager(Intro &in, Score &sc, Plansza &pln) : intro(in), score(sc), pln(pln)
{
    //state = GameManager::GameState::INTRO;
    state = INTRO;
    width=600;
    height=600;
}

void GameManager::debug_changeState()
{
    switch (state)
    {
    case INTRO:
        state = GAME;
        break;
    case GAME:
        state = SCORE;
        break;
    case SCORE:
        // oops - tu powinniśmy jakoś zamknąć aplikację
        break;
    }
}

void GameManager::handleEvent(sf::Event &event)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
    {
        switch (event.mouseButton.button)
        {
        case sf::Mouse::Left:
        {
            pln.revealPos(event.mouseButton.x, event.mouseButton.y,width,height);
            break;
        }
        case sf::Mouse::Right:
        {
            pln.setFlagPos(event.mouseButton.x, event.mouseButton.y,width,height);
            break;
        }
        }
    }
    case sf::Event::KeyPressed:
    {
        if (event.key.code == sf::Keyboard::Space)
        {
            debug_changeState();
        }
    }
    }
}

void GameManager::draw(sf::RenderWindow &window, int width, int height)
{
    switch (state)
    {
    case INTRO:
        intro.draw(window);
        break;
    case GAME:
        pln.displayGraphics(window, height, width);
        pln.drawLines(window,height,width);
        break;
    case SCORE:
        score.draw(window);
        break;
    }
}