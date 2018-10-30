#include "bat.h"

namespace pongShapes {

    Bat::Bat(const sf::Vector2f& dimensions) :
        utils::MovableRectangle(dimensions)
    {
        ;
    }

    void Bat::move(float x, float y) {
        if(x != 0.0f) {
            throw InvalidMovement();
        }
        utils::MovableRectangle::move(0.0f, y);
    }

    void Bat::move(const sf::Vector2f& direction) {
        move(direction.x, direction.y);
    }
} // namespace pongShapes
