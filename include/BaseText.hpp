//
// Created by kaw on 9/24/22.
//

#ifndef SFML_SNAKE_SRC_BASETEXT_HPP_
#define SFML_SNAKE_SRC_BASETEXT_HPP_

#define STANDARD_FONT_PATH "assets/fonts/standard.otf"
#define COOL_FONT_PATH "assets/fonts/cool.otf"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Entity.hpp"
class BaseText {
 protected:
    sf::Text text;
    sf::Font font;
    void setText(std::string newText);
 public:
  BaseText(std::string);
};

#endif //SFML_SNAKE_SRC_BASETEXT_HPP_
