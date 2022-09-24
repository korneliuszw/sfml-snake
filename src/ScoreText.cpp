//
// Created by kaw on 9/24/22.
//

#include "ScoreText.hpp"
#include "Game.hpp"
void ScoreText::draw(sf::RenderWindow *window) {
  window->draw(this->text);
}
void ScoreText::update(sf::Time elapsed, void *context) {
  Game* game = (Game*) context;
  setText("Wynik: " + std::to_string(game->getScore()));
}
void ScoreText::handleEvent(sf::Event events) {
  return;
}
