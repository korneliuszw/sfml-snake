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
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.hpp"

enum class Direction : int {
  LEFT = 270,
  RIGHT = 90,
  TOP = 0,
  BOTTOM = 180,
};

class SnakePart {
 public:
  sf::Sprite sprite;
  Direction direction;
  sf::Vector2f position;
  SnakePart* previous = nullptr;
  SnakePart* next = nullptr;
 public:
  SnakePart(sf::Vector2f);
  bool isDead();
  void updateSprite();
  void update();
};

class Snake : public Entity {
 private:
  float speed = 2;
  Direction direction = Direction::TOP;
  SnakePart* snake;
  SnakePart* tail;
 public:
  Snake();
  void move(sf::Vector2f);
  void update(sf::Time elapsed);
  void handleEvent(sf::Event);
  void draw(sf::RenderWindow *window) override;
  void addPart();
};

#endif //SFML_SNAKE_SRC_SNAKE_HPP_
