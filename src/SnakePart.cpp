//
// Created by kaw on 9/19/22.
//

#include "SnakePart.hpp"
#include "AssetManager.hpp"
#include "Snake.hpp"

void calculateNewPosition(const Direction& direction, sf::Vector2f& pos, const float units) {
  switch (direction) {
    case Direction::TOP: {
      pos.y -= units;
      break;
    }
    case Direction::BOTTOM: {
      pos.y += units;
      break;
    }
    case Direction::LEFT: {
      pos.x -= units;
      break;
    }
    case Direction::RIGHT: {
      pos.x += units;
      break;
    }
  }
}
sf::Vector2f calculateNewPositionCopy(const Direction& direction, const sf::Vector2f& pos, const float units) {
  sf::Vector2f newPos = pos;
  calculateNewPosition(direction, newPos, units);
  return newPos;
}
SnakePart::SnakePart(sf::Vector2f position) {
  this->position = position;
  this->direction = Direction::TOP;
}
