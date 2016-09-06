#include <SFML/Graphics.hpp>

#include "GameState.hpp"
#include "MenuState.hpp"

void MenuState::draw(const float dt) {

    this->game->window.setView(this->view);

    this->game->window.clear(sf::Color(26, 128, 182, 255));
    this->game->window.display();

    return;
}

void MenuState::update(const float dt) {

    
}

void MenuState::handleInput() {

    sf::Event event;

    while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
            {
                game->window.close();
                break;
            }
            case sf::Event::KeyPressed:
            {
                if(event.key.code == sf::Keyboard::Escape) this->game->window.close();
                break;
            }
        }
    }

    return;
}

MenuState::MenuState(Game* game) {

	this->game = game;
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
    this->view.setSize(pos);
    pos *= 0.5f;
    this->view.setCenter(pos);
}
