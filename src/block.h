#include<SFML/Graphics.hpp>

using namespace sf;

class Block {

    private:
        Vector2f position;
        RectangleShape blockShape;
        int state = 1;

    public:
        Block(float startX, float startY);
        FloatRect getPosition();
        RectangleShape getShape();
        int getState();
        void update();
};
