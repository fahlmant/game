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
    int state = 0;

    Bat bat (windowWidth / 2, windowHeight - 20);
    Ball ball (windowWidth/2, 1);
    Block block (windowWidth/2 , windowHeight/2);

    /*    Block block_struct[10];
    for(int i = 0; i < 10; i++)
    {
        block_struct[i] = block_struct(windowWidth/ i*2, windowHeight/i*2);
    }
    */

    Text hud;
    Font font;
    font.loadFromFile("../txt/vcr.ttf");
    hud.setFont(font);
    hud.setCharacterSize(50);
    hud.setColor(sf::Color::White);

    while(window.isOpen())
    {
        //Menu State
        while(state == 0)
        {
            Event event;
            std::stringstream menu;
            menu << "         PLAY" ;
            hud.setString(menu.str());
            while(window.pollEvent(event))
            {
                if(Keyboard::isKeyPressed(Keyboard::Escape) || event.type == Event::Closed)
                {
                    window.close();
                    state = 1;
                }
                else if(event.type = sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                        state = 1;
                    }
                }
            }
            window.clear(Color(26, 128, 182, 255));
            window.draw(hud);
            window.display();
        }
        //Game State
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
                block.changeState(1);
            }
        }

        if(ball.getPosition().top < 0)
        {
            ball.reboundTopAndBat();
        }

        if(ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth)
        {
            ball.reboundSides();
        }

        if(ball.getPosition().intersects(bat.getPosition()))
        {
            ball.reboundTopAndBat();
        }
        if(ball.getPosition().intersects(block.getPosition()) && block.getState())
        {
            ball.reboundTopAndBat();
            score++;
            block.changeState(0);
        }


        ball.update();
        bat.update();

        std::stringstream ss;
        ss << "Score: " << score << "  Lives: " << lives;
        hud.setString(ss.str());

        window.clear(Color(26, 128, 182, 255));
        window.draw(bat.getShape());
        window.draw(ball.getShape());
        if(block.getState())
        {
            window.draw(block.getShape());
        }
        window.draw(hud);
        window.display();
    }
    

    return 0;
}
