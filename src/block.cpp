#include "block.h"

Block::Block(float startX, float startY){

    position.x = startX;
    position.y = startY;

    blockShape.setSize(sf::Vector2f(50, 30));
    blockShape.setPosition(position);
}

FloatRect Block::getPosition(){

    return blockShape.getGlobalBounds();
}

RectangleShape Block::getShape(){

    return blockShape;
}

int Block::getState(){

    return state;
}

void Block::changeState(int new_state){

    state = new_state;
}

void Block::update(){

    blockShape.setPosition(position);
}
