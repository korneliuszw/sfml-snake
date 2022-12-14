//
// Created by kaw on 9/22/22.
//

#ifndef SFML_SNAKE_SRC_APPLEMANAGER_HPP_
#define SFML_SNAKE_SRC_APPLEMANAGER_HPP_

#define APPLE_RESOURCE "apple"

#include <SFML/Graphics.hpp>
#include <list>
#include <random>
#include <optional>
#include "Entity.hpp"
#include "Game.hpp"
constexpr int GENERATE_EVERY_SECONDS = 5;

class AppleManager: public Entity {
 private:
  class Apple: public sf::Drawable {
   public:
    sf::Sprite sprite;
    Apple(sf::Vector2f);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
  };
  static std::shared_ptr<AppleManager> singleton;
  std::list<Apple> apples;
  sf::Clock internalTimer;
  std::mt19937 rng;
  std::uniform_int_distribution<int> random_x = std::uniform_int_distribution(2, TILES_WIDTH - 1);
  std::uniform_int_distribution<int> random_y = std::uniform_int_distribution(2, TILES_HEIGHT - 1);
 public:
  AppleManager();
  void update(sf::Time elapsed, void*) override;
  void handleEvent(sf::Event events) override;
  void draw(sf::RenderWindow *window) override;
  std::optional<std::list<Apple>::iterator> isTouching(const sf::Vector2f&);
  void removeAt(std::list<Apple>::iterator);
  void reset();
  static std::shared_ptr<AppleManager> GetInstance();
};

#endif //SFML_SNAKE_SRC_APPLEMANAGER_HPP_
