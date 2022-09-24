//
// Created by kaw on 9/22/22.
//

#include <SFML/Graphics.hpp>
#include "AppleManager.hpp"
#include "AssetManager.hpp"
#include "Snake.hpp"

void AppleManager::Apple::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(sprite);
}
AppleManager::Apple::Apple(sf::Vector2f pos) {
  this->sprite = createSprite(APPLE_RESOURCE);
  this->sprite.setPosition(tileToReal(pos));
  this->sprite.setScale(TILE_WIDTH / 40.f, TILE_HEIGHT / 40.f);
  this->sprite.setOrigin(this->sprite.getLocalBounds().width / 2, this->sprite.getLocalBounds().height / 2);
}
std::shared_ptr<AppleManager> AppleManager::singleton = nullptr;
std::shared_ptr<AppleManager> AppleManager::GetInstance() {
  if (!singleton)
    singleton = std::make_shared<AppleManager>();
  return singleton;
}
void AppleManager::draw(sf::RenderWindow *window) {
  for (auto it = apples.begin(); it != apples.end(); it++)
    window->draw(*it);
}
void AppleManager::update(sf::Time elapsed, void* context) {
  if (internalTimer.getElapsedTime().asSeconds() < GENERATE_EVERY_SECONDS || ((Game*) context)->died())
    return;
  internalTimer.restart();
  sf::Vector2f newPosition = {static_cast<float>(random_x(rng)), static_cast<float>(random_y(rng))};
  Snake* snake = (Snake*) ((Game*) context)->responsiveEntities["player"].get(); // dangerous!
  // Generate random apple location till most tiles are filled with snake parts
  for (int i = 0; i < TILE_HEIGHT * TILE_WIDTH / 2; i++)  {
    if (!snake->isTouching(newPosition)) {
      // not colliding, create new apple
      apples.push_back(Apple(newPosition));
      return;
    };
    newPosition = {static_cast<float>(random_x(rng)), static_cast<float>(random_y(rng))};
  }
  // the show must go on
}
void AppleManager::handleEvent(sf::Event events) {

}
AppleManager::AppleManager() {
  std::random_device rd;
  this->rng = std::mt19937(rd());
}
std::optional<std::list<AppleManager::Apple>::iterator> AppleManager::isTouching(const sf::Vector2f& rect) {
  for (auto it = this->apples.begin(); it != this->apples.end(); it++)
    if (it->sprite.getGlobalBounds().contains(tileToReal(rect)))
      return it;
  return {};
}
void AppleManager::removeAt(std::list<AppleManager::Apple>::iterator iterator) {
  this->apples.erase(iterator);
}
void AppleManager::reset() {
  this->apples.clear();
}
