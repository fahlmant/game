#include <SFML/Graphics.hpp>
#include <sstream>
#include <stdio.h>

#include "Game.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"

using namespace sf;

int main() {

    Game game;

    game.pushState(new MenuState(&game));
    game.gameLoop();

    return 0;
}
