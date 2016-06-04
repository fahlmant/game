#include<SFML/Graphics.hpp>

using namespace sf;

class Block {

    private:
        Vector2f position;
        RectangleShape blockShape;
        int state;

    public:
        Block(float startX, float startY);
        FloatRect getPosition();
        RectangleShape getShape();
        int getState();
        void changeState(int new_state);
        void update();
};
