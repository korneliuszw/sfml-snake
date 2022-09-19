//
// Created by kawuwu on 9/12/22.
//

#include "Snake.hpp"
#include <AssetManager.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#define SNAKE_START_X 20
#define SNAKE_START_Y 10
#define SNAKE_ASSETS_WIDTH 32
#define SNAKE_ASSETS_HEIGHT 32

bool directionIsVertical(Direction direction) {
  return ((int) direction) % 180 == 0;
}
void SnakePart::updateSprite() {
  if (this->previous == nullptr)
    this->sprite = createSprite(HEAD_RESOURCE);
  else if (this->next == nullptr) {
    this->sprite = createSprite(TAIL_RESOURCE);
  } else if (this->next && this->previous) {
    if (this->next->position.x != this->previous->position.x && this->next->position.y != this->previous->position.y)
      this->sprite = createSprite(ANGLE_BODY_RESOURCE);
  } else
    this->sprite = createSprite(BODY_STRAIGHT_RESOURCE);
  auto spritePos = this->position;
  spritePos.y = round(this->position.y);
  spritePos.x = round(this->position.x);
  spritePos *= 3.f;
  this->sprite.rotate((float) this->direction);
  this->sprite.setPosition(spritePos);
}
SnakePart::SnakePart(sf::Vector2f position) {
  this->position = position;
  this->direction = Direction::TOP;
}
void Snake::update(sf::Time elapsed) {
  float move = this->speed * elapsed.asSeconds();
  sf::Vector2f newPos = this->snake->position;
  switch (this->direction) {
    case Direction::TOP: {
      newPos.y -= move;
      break;
    }
    case Direction::BOTTOM: {
      newPos.y += move;
      break;
    }
    case Direction::LEFT: {
      newPos.x -= move;
      break;
    }
    case Direction::RIGHT: {
      newPos.x += move;
      break;
    }
  }
  this->move(newPos);
}
void Snake::move(sf::Vector2f newPos) {
  SnakePart* head = this->tail;
  while (head->previous) {
    head->position = head->previous->position;
    head->direction = head->previous->direction;
    head = head->previous;
  }
  this->snake->position = newPos;
  this->snake->position.y -= 1;
  this->snake->direction = this->direction;
}
Snake::Snake() {
  this->snake = this->tail = new SnakePart({SNAKE_START_X, SNAKE_START_Y});
  this->addPart();
}
void Snake::handleEvent(sf::Event event) {
  if (event.type != sf::Event::EventType::KeyPressed)
    return;
  auto keyEvent = event.key;
  switch (keyEvent.code) {
    case sf::Keyboard::W: {
      this->direction = Direction::TOP;
      break;
    }
    case sf::Keyboard::S: {
      this->direction = Direction::BOTTOM;
      break;
    }
    case sf::Keyboard::D: {
      this->direction = Direction::RIGHT;
      break;
    }
    case sf::Keyboard::A: {
      this->direction = Direction::LEFT;
      break;
    }
  }

}
void Snake::draw(sf::RenderWindow *window) {
  auto head = this->snake;
  while (head != nullptr) {
    head->updateSprite();
    window->draw(head->sprite);
    head = head->next;
  }
}
void Snake::addPart() {
  this->tail->next = new SnakePart({0, 0});
  this->tail->next->previous = this->tail;
  this->tail = this->tail->next;
}
