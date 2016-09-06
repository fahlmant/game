#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include <SFML/Graphics.hpp>

#include "GameState.hpp"

class MenuState : public GameState {

    private:

        sf::View view;

    public:

        virtual void draw(const float dt);
        virtual void update(const float dt);
        virtual void handleInput();

        MenuState(Game* game);
};

#endif /* MENU_STATE_HPP */
