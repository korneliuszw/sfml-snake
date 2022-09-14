//
// Created by kawuwu on 9/12/22.
//

#ifndef SFML_SNAKE_SRC_SNAKE_HPP_
#define SFML_SNAKE_SRC_SNAKE_HPP_

#define TAIL_RESOURCE "tail_end"
#define BODY_STRAIGHT_RESOURCE "tail_body"
#define HEAD_RESOURCE "head"
#define ANGLE_BODY_RESOURCE "angle_body"

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>

enum Direction {
  LEFT,
  RIGHT,
  TOP,
  BOTTOM
};

class SnakePart {
 private:
  sf::Sprite sprite;
  Direction direction;
  sf::Vector2f position;
  float rotate;
 public:
  SnakePart* previous;
  SnakePart* next;
 public:
  void move();
  bool isDead();
  void updateSprite();
  void update();
  void handleKeyEvent(sf::Keyboard::Key);
};

class Snake : public sf::Drawable {
 private:
  float speed;
  Direction direction;
 public:
  void update
  void draw(sf::RenderTarget& target, sf::RenderStates states);
};

#endif //SFML_SNAKE_SRC_SNAKE_HPP_
