#include <SFML/Graphics.hpp>
#include "bat.h"

#define windowHeight 800
#define windowWidth 1024

using namespace sf;

int main() {

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Game");

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
