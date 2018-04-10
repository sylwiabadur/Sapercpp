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
    state=INTRO;
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
    Plansza::window->close();
        break;
    }
}

void GameManager::handleEvent(sf::Event &event)
{
    bool change = false;
    switch (state)
    {
        case INTRO:
            change = intro.handleEvent(event);
            break;
        case GAME:
            change = pln.handleEvent(event,width,height);
            break;
        case SCORE:
            change = score.handleEvent(event);
            break;
        }
        if(change)
            debug_changeState();
}

void GameManager::handleMouse(sf::Event &event)
{
    switch(event.type)
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
        }}
}


void GameManager::draw(sf::RenderWindow &window, int width, int height,sf::Event &event)
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
void GameManager::updateState(sf::Event &event) {

 //   dostaje wiadomosc od intro i od score i zmienia stan
    if(score.handleEvent(event))
    {
        debug_changeState();
    }
    else if(intro.handleEvent(event))
    {
        debug_changeState();
    }

}