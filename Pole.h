
#ifndef UNTITLED5_POLE_H
#define UNTITLED5_POLE_H


class Pole{
    bool czyMina;
    bool czyOdkryte;
    bool czyFlaga;

public:
    int minyWokol;
    void ileMinWokol(int miny);
    void postawMine();
    void usunMine();
    void postawFlage();
    void Odkryj();
    void Zakryj();
    bool odczytMiny();
    bool odczytFlagi();
    bool odczytOdkrycia();
    void info();
    int typPola();
    sf::Text getTexts(sf::RenderWindow & window);
    sf::RectangleShape getRect(sf::RenderWindow &window, int width, int height);
    Pole();

};

#endif //UNTITLED5_POLE_H