//
// Created by kaw on 9/24/22.
//

#ifndef SFML_SNAKE_SRC_SCORETEXT_HPP_
#define SFML_SNAKE_SRC_SCORETEXT_HPP_

#include "BaseText.hpp"
class ScoreText: public BaseText, public Entity {
 public:
  ScoreText(): BaseText(STANDARD_FONT_PATH) {};
  void draw(sf::RenderWindow *window) override;
  void update(sf::Time elapsed, void *context) override;
  void handleEvent(sf::Event events) override;
};

#endif //SFML_SNAKE_SRC_SCORETEXT_HPP_
