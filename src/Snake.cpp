//
// Created by kawuwu on 9/12/22.
//

#include "Snake.hpp"
#include <AssetManager.hpp>
#include <AppleManager.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#define SNAKE_START_X 20
#define SNAKE_START_Y 20

bool directionIsVertical(Direction direction) {
  return ((int) direction) % 180 == 0;
}
void Snake::update(sf::Time elapsed, void* context) {
  if (isDead()) return;
  if (wasInput) {
    this->addPart();
    this->parts.pop_back();
  }
  auto& pos = this->parts.begin()->position;
  sf::Vector2i intPos = static_cast<sf::Vector2i>(this->parts.begin()->position);
  if (intPos != previousPosition) {
    handleAppleTouch();
  }
  previousPosition = intPos;
  this->wasInput = false;
}
Snake::Snake() {
  this->addPart();
  this->addPart();
  this->addPart();
}
void Snake::handleEvent(sf::Event event) {
  // Figure out KeyPressed vs other key event, may cause issue with wasInput
  if (event.type != sf::Event::EventType::KeyReleased)
    return;
  this->wasInput = true;
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
  for (auto head = this->parts.begin(); head != this->parts.end(); head++) {
    auto next = ++head;
    auto previous = --head;
    if (head == this->parts.begin())
      head->sprite = createSprite(HEAD_RESOURCE);
    else if (head == --this->parts.end())
      head->sprite = createSprite(TAIL_RESOURCE);
    else if (next->position.x != head->position.x && next->position.y != head->position.y)
        head->sprite = createSprite(ANGLE_BODY_RESOURCE);
    else
      head->sprite = createSprite(BODY_STRAIGHT_RESOURCE);

    head->sprite.rotate((float) this->direction);
    head->sprite.setPosition(tileToReal(head->position));
    window->draw(head->sprite);
  }
}
void Snake::addPart() {
  auto newPart = SnakePart({SNAKE_START_X, SNAKE_START_Y});
  if (!this->parts.empty()) newPart.position = this->parts.front().position;
  calculateNewPosition(this->direction, newPart.position, 1);
  this->parts.push_front(newPart);
}
bool Snake::isTouching(const sf::Vector2f& pos) {
  for (auto it = this->parts.begin(); it != this->parts.end(); it++)
    if (it->position == pos)
      return true;
  return false;
}
void Snake::handleAppleTouch() {
  auto manager = AppleManager::GetInstance();
  auto touch = manager->isTouching(this->parts.begin()->position);
  if (!touch.has_value())
    return;
  this->addPart();
  manager->removeAt(touch.value());
}
bool Snake::isDead() {
  auto headPos = this->parts.begin()->position;
  bool borderCollide =  headPos.x < 1 || headPos.x > TILES_WIDTH || headPos.y < 1 || headPos.x > TILES_HEIGHT;
  if (borderCollide) return true;
  for (auto it = --this->parts.end(); it != this->parts.begin(); it--) {
    if (it->position == headPos) return true;
  }
  return false;
}