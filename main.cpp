#include <SFML/Graphics.hpp>
#include "bat.h"
#include "ball.h"
#include <SFML/Graphics.hpp>

#define windowHeight 800
#define windowWidth 1024

using namespace sf;

int main() {

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Game");

    int score = 0;
    int lives = 3;

    Bat bat (windowWidth / 2, windowHeight - 20);
    Ball ball (windowWidth/2, 1);
    Text hud;
    Font font;
    font.loadFromFile("txt/vcr.ttf");
    hud.setFont(font);
    hud.setCharacterSize(50);
    hud.setColor(sf::Color::White);

    while(window.isOpen())
    {
        Event e;
        while(window.pollEvent(e))
        {
            if(e.type == Event::Closed)
            {
                window.close();
            }
        }
    }
    


    return 0;
}
