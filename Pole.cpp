#include <SFML/Graphics.hpp>
#include "Pole.h"
#include "Plansza.h"
#include <iostream>
#include<string>
Pole::Pole()
{
    czyMina = false;
    czyOdkryte = false;//zakryte
    czyFlaga = false;
    minyWokol=0;
}
void Pole::ileMinWokol(int miny){
    minyWokol=miny;
}
void Pole::info()
{
    int a = czyMina;
    int b = czyOdkryte;
    int c = czyFlaga;
    std::cout << a << b << c;
}
void Pole::postawMine()
{
    czyMina = true;
}
void Pole::usunMine()
{
    czyMina = false;
}
void Pole::postawFlage()
{
    czyFlaga = !czyFlaga;
}
void Pole::Odkryj()
{
    czyOdkryte = true;
}
void Pole::Zakryj()
{
    czyOdkryte = false;
}
bool Pole::odczytFlagi()
{
    return czyFlaga;
}
bool Pole::odczytMiny()
{
    return czyMina;
}
bool Pole::odczytOdkrycia()
{
    return czyOdkryte;
}
int Pole::typPola()
{
    if (!odczytOdkrycia() && !odczytFlagi()) //zakryte bez flagi
        return 1;
    if (odczytOdkrycia() && odczytMiny() && !odczytFlagi()) // odkryte z mina bez flagi
        return 2;
    if (!odczytOdkrycia() && odczytFlagi()) //zakryte z flaga
        return 3;
    if (odczytOdkrycia() && !odczytMiny()) //odkryte bez miny bez flagi
        return 4;
    return -1;
}
sf::Text Pole::getTexts(sf::RenderWindow &window)
{
    sf::Text text;
    text.setFont(Plansza::font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    switch (typPola())
    {
    case 4:
        text.setString(std::to_string(minyWokol));
        break;
    default:
        text.setString("");
    }
    return text;
}
sf::RectangleShape Pole::getRect(sf::RenderWindow &window, int width, int height)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(width * 0.1, height * 0.1));
    switch (typPola())
    {
    case 2:
        rectangle.setFillColor(sf::Color(255, 0, 0)); //czerwone z mina
        break;
    case 4:
        rectangle.setFillColor(sf::Color(0, 255, 0)); // zielone odkryte bez miny bez flagi
        break;
    case 3:
        rectangle.setFillColor(sf::Color(0, 0, 255)); //niebieskie zakryte z flaga
        break;
    case 1:
        rectangle.setFillColor(sf::Color(0, 0, 0)); //czarne zakryte bez flagi
        break;
    default:
        rectangle.setFillColor(sf::Color(0, 0, 0));
    }
    return rectangle;
}