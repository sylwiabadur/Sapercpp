// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include "Pole.h"
// #include "Plansza.h"
// using namespace std;
// using namespace sf;

// int main()
// {
//     const int height = 600;
//     const int width = height;
//     RenderWindow window(VideoMode(height, width), "SFML window");
//     window.setFramerateLimit(30);
//     VertexArray linie(Lines);
//     Plansza pln;
//     bool firstTime = true;
//     // Create the main window
//     Font font;
//     if (!font.loadFromFile("arial.ttf"))
//     {
//         cout << "Blad w ladowaniu czcionki" << endl;
//     }
//     Plansza::font = font;
//     Plansza::window = &window;
//     for (int x = 0; x < height; x += 60)
//     {
//         linie.append(Vector2f(0 + x, 0));      // początek
//         linie.append(Vector2f(0 + x, height)); // koniec
//         linie.append(Vector2f(0, 0 + x));      // początek
//         linie.append(Vector2f(width, 0 + x));  // koniec
//     };

//     // Start the game loop
//     while (window.isOpen())
//     {
//         // Process events
//         Event event;
//         while (window.pollEvent(event))
//         {

//             switch (event.type)
//             {
//             case Event::Closed:
//             {
//                 window.close();
//                 break;
//             }
//             case Event::MouseButtonPressed:
//             {
//                 switch (event.mouseButton.button)
//                 {
//                 case Mouse::Left:
//                 {
//                     pln.revealPos(event.mouseButton.x, event.mouseButton.y);
//                     break;
//                 }
//                 case Mouse::Right:
//                 {
//                     pln.setFlagPos(event.mouseButton.x, event.mouseButton.y);
//                     break;
//                 }
//                 }
//             }
//             }
//         }
//         // Clear screen
//         window.clear();
//         //renderPlansza(window, height, width)
//         pln.displayGraphics(window, width, height);
//         window.draw(linie);
//         // Update the window
//         window.display();
//     }

//     return EXIT_SUCCESS;
// }

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pole.h"
#include "Plansza.h"
#include "Intro.h"
#include "Score.h"
#include "GameManager.h"
using namespace std;
using namespace sf;

int main()
{
    const int height = 600;
    const int width = height;
    RenderWindow window(VideoMode(height, width), "SFML window");
    window.setFramerateLimit(30);
    bool firstTime = true;
    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "Blad w ladowaniu czcionki" << endl;
    }

    Intro intro;
    Plansza pln;
    Score score;
    Plansza::font = font;
    Plansza::window = &window;
    GameManager gm(intro, score, pln);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                window.close();

            gm.handleEvent(event);
        }
        window.clear();
        gm.draw(window, width, height);
        window.display();
    }

    return EXIT_SUCCESS;
}
