//
// Created by kaw on 9/19/22.
//

#ifndef SFML_SNAKE_SRC_SNAKEPART_HPP_
#define SFML_SNAKE_SRC_SNAKEPART_HPP_

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>


enum class Direction : int {
  LEFT = 270,
  RIGHT = 90,
  TOP = 0,
  BOTTOM = 180,
};

void calculateNewPosition(const Direction& direction, sf::Vector2f& pos, const float units);
sf::Vector2f calculateNewPositionCopy(const Direction& direction, const sf::Vector2f& pos, const float units);

class SnakePart {
 public:
  sf::Sprite sprite;
  Direction direction;
  sf::Vector2f position;
 public:
  SnakePart(sf::Vector2f);
};

#endif //SFML_SNAKE_SRC_SNAKEPART_HPP_
