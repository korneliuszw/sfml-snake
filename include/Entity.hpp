//
// Created by kaw on 9/15/22.
//

#ifndef SFML_SNAKE_SRC_ENTITY_HPP_
#define SFML_SNAKE_SRC_ENTITY_HPP_

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
class Entity {
 public:
  virtual void draw(sf::RenderWindow*) = 0;
  virtual void update(sf::Time elapsed, void* context) = 0;
  virtual void handleEvent(sf::Event events) = 0;
};

#endif //SFML_SNAKE_SRC_ENTITY_HPP_
