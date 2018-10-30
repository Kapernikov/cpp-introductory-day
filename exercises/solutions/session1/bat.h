#ifndef BAT_INCLUDE
#define BAT_INCLUDE

#include <exception>
#include <string>

#include "movableRectangle.h"

namespace pongShapes {
    class InvalidMovement : public std::exception {};

    class Bat : public utils::MovableRectangle {
        public:
            Bat(const sf::Vector2f& dimensions);
            Bat(const Bat& other) = default;
            Bat(Bat&& other) = default;

            ~Bat() = default;

            Bat& operator=(const Bat& other) = default;
            Bat& operator=(Bat&& other) = default;

            /**
             * @throws InvalidMovement
             */
            void move(float x, float y) override;

            /**
             * @throws InvalidMovement
             */
            void move(const sf::Vector2f& direction) override;
    }; 
} // namespace pongShapes

#endif  /* BAT_INCLUDE */
