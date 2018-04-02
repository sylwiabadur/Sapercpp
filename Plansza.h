//
// Created by c on 28.02.18.
//
#include "Pole.h"
#ifndef UNTITLED5_PLANSZA_H
#define UNTITLED5_PLANSZA_H

class Plansza
{
    int m;
    int n;
    bool koniecGry;
    bool firstTime;
    Pole tab[10][10];
    bool czyPlansza(int x, int y);
   // friend class Score;

  public:
    Plansza();
    void deployMines(int x, bool random);
    void debug_display();
    bool hasMine(int x, int y);
    int countMines(int x, int y);
    void display();
    void reveal(int x, int y);
    void postawFlage(int x, int y);
    void usunFlage(int x, int y);
    void displayGraphics(sf::RenderWindow &window, int width, int height);
    void drawLines(sf::RenderWindow &window, int width, int height);
    void revealPos(int x, int y,int width,int height);
    void setFlagPos(int x, int y,int width,int height);
    void ustawKoniec();
    void ustawPrzegrana();
    void ustawWygrana();
    void czyWygrana();
    bool stanKoncowy();
    static sf::Font font;
    static sf::RenderWindow *window;
    static bool wygrana;
    static int licznikRuchow;
};

#endif //UNTITLED5_PLANSZA_H