//
// Created by kaw on 9/24/22.
//

#ifndef SFML_SNAKE_SRC_GAMEOVERTEXT_HPP_
#define SFML_SNAKE_SRC_GAMEOVERTEXT_HPP_

#include "Entity.hpp"
#include "BaseText.hpp"

class GameOverText: BaseText, public Entity {
 public:
  GameOverText(sf::RenderWindow* window);
  void draw(sf::RenderWindow *window);
  void update(sf::Time elapsed, void *context) override;
  void handleEvent(sf::Event events) override;
};

#endif //SFML_SNAKE_SRC_GAMEOVERTEXT_HPP_
