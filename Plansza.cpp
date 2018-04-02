#include <SFML/Graphics.hpp>
#include "Plansza.h"
#include "Pole.h"
#include <iostream>
#include <ctime>
#include <iomanip>
Plansza::Plansza()
{
    m = 10; //wierszy
    n = 10; //kolumn
    koniecGry = false;
    firstTime = true;
}
int Plansza::licznikRuchow=0;
bool Plansza::wygrana =false;
sf::Font Plansza::font;
sf::RenderWindow *Plansza::window;
bool Plansza::czyPlansza(int x, int y)
{
    return (x < m && y < n && x >= 0 && y >= 0);
}
void Plansza::deployMines(int a, bool random)
//ilosc min i czy randomowo czy nie
{
    if (random == true)
    {
        srand(time(NULL));
        for (int i = 0; i < a; i++)
        {
            int x = rand() % (m - 1);
            int y = rand() % (n - 1);
            tab[x][y].postawMine();
        }
    }
    else if (random == false)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j >= 0)
                {
                    tab[i][j].postawMine();
                }
                if (i == j)
                {
                    tab[i][j].postawMine();
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tab[i][j].ileMinWokol(countMines(i, j));
        }
    }
}
void Plansza::debug_display()
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << std::setw(2);
            tab[i][j].info();
            if (j == 9)
            {
                std::cout << std::endl;
            }
        }
    }
}
bool Plansza::hasMine(int x, int y)
{
    if (this->czyPlansza(x, y))
    {
        if (tab[x][y].odczytMiny() == true)
        {
            return true;
        }
    }
    return false;
}
int Plansza::countMines(int x, int y)
{
    int l = 0;
    l += hasMine(x - 1, y);
    l += hasMine(x - 1, y - 1);
    l += hasMine(x - 1, y + 1);
    l += hasMine(x, y - 1);
    l += hasMine(x, y + 1);
    l += hasMine(x + 1, y);
    l += hasMine(x + 1, y + 1);
    l += hasMine(x + 1, y - 1);
    return l;
}
void Plansza::display()
{

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << std::setw(2);
            if (!tab[i][j].odczytOdkrycia() && !tab[i][j].odczytFlagi())
            {
                std::cout << "[.]";
            }
            else if (!tab[i][j].odczytOdkrycia() && tab[i][j].odczytFlagi())
            {
                std::cout << " ? ";
            }
            else if (tab[i][j].odczytOdkrycia() && !tab[i][j].odczytMiny() && countMines(i, j) == 0)
            {
                std::cout << "   ";
            }
            else if (tab[i][j].odczytOdkrycia() && !tab[i][j].odczytMiny() && countMines(i, j) == 3)
            {
                std::cout << " 3 ";
            }
            else if (tab[i][j].odczytMiny())
            {
                std::cout << " x ";
            }
            else
            {
                std::cout << "   ";
            }
            if (j == 9)
            {
                std::cout << std::endl;
            }
        }
    }
}

void Plansza::reveal(int x, int y)
{
    tab[x][y].Odkryj();
    if (tab[x][y].odczytMiny())
    {
        koniecGry = true;
        ustawKoniec();
    }
    else
    {

        if (tab[x][y].minyWokol == 0 && !hasMine(x - 1, y) && czyPlansza(x - 1, y) && !tab[x - 1][y].odczytOdkrycia())
        {
            reveal(x - 1, y);
        }
        if (tab[x][y].minyWokol == 0 && !hasMine(x, y - 1) && czyPlansza(x, y - 1) && !tab[x][y - 1].odczytOdkrycia())
        {
            reveal(x, y - 1);
        }
        if (tab[x][y].minyWokol == 0 && !hasMine(x, y + 1) && czyPlansza(x, y + 1) && !tab[x][y + 1].odczytOdkrycia())
        {
            reveal(x, y + 1);
        }
        if (tab[x][y].minyWokol == 0 && !hasMine(x + 1, y) && czyPlansza(x + 1, y) && !tab[x + 1][y].odczytOdkrycia())
        {
            reveal(x + 1, y);
        }
        if (tab[x][y].minyWokol == 0 && !hasMine(x - 1, y - 1) && czyPlansza(x - 1, y - 1) && !tab[x - 1][y - 1].odczytOdkrycia())
        {
            reveal(x - 1, y - 1);
        }
        if (tab[x][y].minyWokol == 0 && !hasMine(x - 1, y + 1) && czyPlansza(x - 1, y + 1) && !tab[x - 1][y + 1].odczytOdkrycia())
        {
            reveal(x - 1, y + 1);
        }
        if (tab[x][y].minyWokol == 0 && !hasMine(x + 1, y + 1) && czyPlansza(x + 1, y + 1) && !tab[x + 1][y + 1].odczytOdkrycia())
        {
            reveal(x + 1, y + 1);
        }
        if (tab[x][y].minyWokol == 0 && !hasMine(x + 1, y - 1) && czyPlansza(x + 1, y - 1) && !tab[x + 1][y - 1].odczytOdkrycia())
        {
            reveal(x + 1, y - 1);
        }
    }
}
void Plansza::postawFlage(int x, int y)
{
    tab[x][y].postawFlage();
}
void Plansza::displayGraphics(sf::RenderWindow &window, int width, int height)
{
    sf::Text text;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            sf::RectangleShape rect = tab[j][i].getRect(window, width, height);
            text = tab[j][i].getTexts(window);
            rect.setPosition(width * 0.1 * i, height * 0.1 * j);
            text.setPosition(width * 0.1 * i + 20, height * 0.1 * j + 15);
            window.draw(rect);
            window.draw(text);
        }
    }
}
void Plansza::drawLines(sf::RenderWindow &window, int width, int height)
{
    sf::VertexArray linie(sf::Lines);
    for (int x = 0; x < height; x += 60)
    {
        linie.append(sf::Vector2f(0 + x, 0));      // początek
        linie.append(sf::Vector2f(0 + x, height)); // koniec
        linie.append(sf::Vector2f(0, 0 + x));      // początek
        linie.append(sf::Vector2f(width, 0 + x));  // koniec
    }
    window.draw(linie);
}
void Plansza::revealPos(int x, int y, int width, int height)
{
    int kolumna = x / (width / n);
    int rzad = y / (height / m);
    licznikRuchow++;
    std::cout<<licznikRuchow<<std::endl;

    if (firstTime)
    {
        deployMines(30, 1);
        if (tab[rzad][kolumna].odczytMiny() == true)
        {
            tab[rzad][kolumna].usunMine();
        }
    }
    firstTime = false;
    this->reveal(rzad, kolumna);
    czyWygrana();
}

void Plansza::setFlagPos(int x, int y,int width,int height)
{
    int kolumna = x / (width/n);
    int rzad = y / (height/m);
    licznikRuchow++;
    this->tab[rzad][kolumna].postawFlage();
    czyWygrana();
}
void Plansza::ustawKoniec()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!tab[i][j].odczytOdkrycia())
            {
                reveal(i, j);
            }
        }
    }
    if (koniecGry)
    {
        ustawPrzegrana();
    }
    if (Plansza::wygrana)
    {
        ustawWygrana();
    }
}
void Plansza::ustawPrzegrana()
{
    Plansza::window;
    sf::Text text;
    text.setFont(Plansza::font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Yellow);
    text.setString("GAME OVER");
    text.setStyle(sf::Text::Bold);
    text.setPosition(150, 270);
    window->draw(text);
}
void Plansza::ustawWygrana()
{
    Plansza::window;
    sf::Text text;
    text.setFont(Plansza::font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Yellow);
    text.setString("WIN");
    text.setStyle(sf::Text::Bold);
    text.setPosition(250, 270);
    window->draw(text);
    std::cout << "wygrana";
}
void Plansza::czyWygrana()
{
    int m = 0; //mina
    int l = 0; //mina i zakryte
    int f = 0; //flaga i mina
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (tab[i][j].odczytMiny())
            {
                m++;
            }
            if (!tab[i][j].odczytOdkrycia())
            {
                l++;
            }
            if (tab[i][j].odczytFlagi() && !tab[i][j].odczytOdkrycia())
            {
                f++;
            }
        }
    }
    if (m == l && m != 0 && l != 0 || (m == f && m != 0 && f != 0))
    {
        Plansza::wygrana = true;
        ustawKoniec();
    }
}