#include <SFML/Graphics.hpp>
#include "bat.h"
#include "ball.h"
#include "block.h"
#include <sstream>
#include <SFML/Graphics.hpp>

#define windowHeight 600
#define windowWidth 800

using namespace sf;

int main() {

    RenderWindow window(VideoMode(windowWidth, windowHeight), "Game");

    int score = 0;
    int lives = 3;

    Bat bat (windowWidth / 2, windowHeight - 20);
    Ball ball (windowWidth/2, 1);
    Block block (windowWidth/2 , windowHeight/2);
    Text hud;
    Font font;
    font.loadFromFile("../txt/vcr.ttf");
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
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            if(bat.getPosition().left > 0)
            {
                bat.moveLeft();
            }
        }
        else if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            if(bat.getPosition().left + 50 < windowWidth)
            {
                bat.moveRight();
            }
        }
        else if(Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if(ball.getPosition().top > windowHeight)
        {
            ball.hitBot();
            lives --;
            if(lives < 1)
            {
                score = 0;
                lives = 3;
            }
        }

        if(ball.getPosition().top < 0)
        {
            ball.reboundTopAndBat();
            score++;
        }

        if(ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
        {
            ball.reboundSides();
        }

        if(ball.getPosition().intersects(bat.getPosition()))
        {
            ball.reboundTopAndBat();
        }


        ball.update();
        bat.update();

        std::stringstream ss;
        ss << "Score: " << score << "  Lives: " << lives;
        hud.setString(ss.str());

        window.clear(Color(26, 128, 182, 255));
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        window.draw(block.getShape());
        window.draw(hud);
        window.display();
    }
    

    return 0;
}
