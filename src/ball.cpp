#include "ball.h"

Ball::Ball(float startX, float startY){

    position.x = startX;
    position.y = startY;

    xVel = .2f;
    yVel = .2f;

    ballShape.setSize(sf::Vector2f(10, 10));
    ballShape.setPosition(position);
}

FloatRect Ball::getPosition(){

    return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape(){

    return ballShape;
}

float Ball::getXVel(){

    return xVel;
}

void Ball::reboundSides(){

    xVel = -xVel;
}

void Ball::reboundTopAndBat(){

    position.y -= (yVel * 30);
    yVel = -yVel;
}

void Ball::hitBot(){

    position.y = 1;
    position.x = 500;
}

void Ball::update(){

    position.x += xVel;
    position.y += yVel;
    ballShape.setPosition(position);
}
