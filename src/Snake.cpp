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
  if (isDead() ) {
    auto game = (Game*) context;
    if (!game->died())
      game->die();
    return;
  }
  if (wasInput) {
    this->addPart();
    this->parts.pop_back();
    this->updateSprites();
  }
  auto& pos = this->parts.begin()->position;
  sf::Vector2i intPos = static_cast<sf::Vector2i>(this->parts.begin()->position);
  if (intPos != previousPosition) {
    if (handleAppleTouch())
      ((Game*) context)->addScore(100);
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
  auto keyEvent = event.key;
  switch (keyEvent.code) {
    case sf::Keyboard::W: {
      if (this->direction != Direction::BOTTOM)
        this->direction = Direction::TOP;
      this->wasInput = true;
      break;
    }
    case sf::Keyboard::S: {
      if (this->direction != Direction::TOP)
        this->direction = Direction::BOTTOM;
      this->wasInput = true;
      break;
    }
    case sf::Keyboard::D: {
      if (this->direction != Direction::LEFT)
        this->direction = Direction::RIGHT;
      this->wasInput = true;
      break;
    }
    case sf::Keyboard::A: {
      if (this->direction != Direction::RIGHT)
      this->direction = Direction::LEFT;
      this->wasInput = true;
      break;
    }
  }
}
void Snake::draw(sf::RenderWindow *window) {
  for (auto part: this->parts)
    window->draw(part.sprite);
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
bool Snake::handleAppleTouch() {
  auto manager = AppleManager::GetInstance();
  auto touch = manager->isTouching(this->parts.begin()->position);
  if (!touch.has_value())
    return false;
  this->addPart();
  manager->removeAt(touch.value());
  return true;
}
bool Snake::isDead() {
  auto headBounds = this->parts.begin()->sprite.getGlobalBounds();
  auto& headPos = this->parts.begin()->position;
  bool borderCollide =  headPos.x < 1 || headPos.x > TILES_WIDTH || headPos.y < 1 || headPos.y > TILES_HEIGHT;
  if (borderCollide) return true;
  if (this->parts.size() < 4) return false;
  for (auto it = std::next(this->parts.begin(), 3); it != this->parts.end(); it++) {
    if (it->sprite.getGlobalBounds().intersects(headBounds))
      return true;
  }
  return false;
}
void Snake::updateSprites() {
  auto head = this->parts.begin();
  for (int i = 0; i < this->parts.size(); i++)
  {
    Direction direction = this->direction;
    if (i == 0) {
      head->sprite = createSprite(HEAD_RESOURCE);
    }
      // warning! if hell below!
    else {
      auto previous = std::prev(head);
      if (previous->position.x > head->position.x)
        direction = Direction::RIGHT;
      else if (previous->position.x < head->position.x)
        direction = Direction::LEFT;
      else if (previous->position.y > head->position.y)
        direction = Direction::BOTTOM;
      else if (previous->position.y < head->position.y)
        direction = Direction::TOP;
      if (i == this->parts.size() - 1) {
        head->sprite = createSprite(TAIL_RESOURCE);
      }
      else {
        auto next = std::next(head);
        if (next->position.x != previous->position.x && next->position.y != previous->position.y) {
          head->sprite = createSprite(ANGLE_BODY_RESOURCE);
          // common tail angle issue
          // i hate those if else if but can I do any better?
          if (direction == Direction::RIGHT && next->position.y > head->position.y)
            direction = Direction::BOTTOM;
          else if (direction == Direction::TOP && next->position.x > head->position.x)
            direction = Direction::RIGHT;
          else if (direction == Direction::BOTTOM && next->position.x < head->position.x)
            direction = Direction::LEFT;
          else if (direction == Direction::LEFT && next->position.y < head->position.y)
            direction = Direction::TOP;
        }
        else
          head->sprite = createSprite(BODY_STRAIGHT_RESOURCE);
      }
    }
    head->sprite.rotate((float) direction);
    head->sprite.setScale(TILE_WIDTH / 40.f, TILE_HEIGHT / 40.f );
    head->sprite.setOrigin(head->sprite.getLocalBounds().width / 2, head->sprite.getLocalBounds().height / 2);
    head->sprite.setPosition(tileToReal(head->position));
    head = std::next(head);
  }
}
