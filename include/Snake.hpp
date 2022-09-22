//
// Created by kawuwu on 9/12/22.
//

#ifndef SFML_SNAKE_SRC_SNAKE_HPP_
#define SFML_SNAKE_SRC_SNAKE_HPP_

#define TAIL_RESOURCE "tail_end"
#define BODY_STRAIGHT_RESOURCE "tail_body"
#define HEAD_RESOURCE "head"
#define ANGLE_BODY_RESOURCE "angle_body"
#include <list>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Entity.hpp"
#include "SnakePart.hpp"

class Snake : public Entity {
 private:
  float speed = 1;
  Direction direction = Direction::TOP;
  sf::Vector2i previousPosition;
  std::list<SnakePart> parts;
  bool wasInput;
  void addPart();
  void checkGameState();
  bool isDead();
  int touchingApples();
 public:
  Snake();
  void update(sf::Time elapsed);
  void updateDirection(Direction);
  void handleEvent(sf::Event);
  void draw(sf::RenderWindow *window) override;
  bool isTouching(const sf::Vector2f&);
};

#endif //SFML_SNAKE_SRC_SNAKE_HPP_
