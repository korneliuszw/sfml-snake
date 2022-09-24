//
// Created by kaw on 9/24/22.
//

#include "BaseText.hpp"
#include "Game.hpp"


void BaseText::setText(std::string newText) {
  this->text.setString(newText);
}
BaseText::BaseText(std::string fontPath) {
  this->font.loadFromFile(fontPath);
  this->text.setFont(this->font);
  this->text.setCharacterSize(48);
  this->text.setFillColor(sf::Color::Black);
  this->text.setStyle(sf::Text::Regular);
}
