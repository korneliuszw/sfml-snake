//
// Created by kaw on 9/24/22.
//

#include "GameOverText.hpp"
#include "Game.hpp"
#include "Highscores.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <sstream>
void GameOverText::update(sf::Time elapsed, void *context) {
  // possible optimization here: add a variable to the main loop to stop sending updates after notyfing everyone of death
  if (((Game *) context)->died()) {
    std::ostringstream baseText;
    baseText << "Przegrales\nR = reset\n";
    auto highscores = Highscores::GetInstance();
    int i = 1;
    auto scoresSet = highscores->getScores();
    for (auto score = scoresSet.rbegin(); score != scoresSet.rend(); score++) {
      baseText << i <<  ". " << *score << "\n";
      i++;
    }
    this->setText(baseText.str());
  }
}
void GameOverText::handleEvent(sf::Event events) {

}
GameOverText::GameOverText(sf::RenderWindow* window): BaseText(COOL_FONT_PATH) {
  auto bounds = this->text.getLocalBounds();
  this->text.setOrigin(std::round(bounds.left + bounds.width / 2.0f), std::round(bounds.top + bounds.height / 2.0f));
  this->text.setPosition(100, window->getView().getCenter().y);
  this->text.setFillColor(sf::Color::Red);
}
void GameOverText::draw(sf::RenderWindow *window) {
  window->draw(this->text);
}
