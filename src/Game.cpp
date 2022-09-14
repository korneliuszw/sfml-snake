//
// Created by kawuwu on 9/12/22.
//

#include "Game.hpp"
void Game::setMainEventHandler(EventHandler eventHandler) {
  this->eventHandlerMain = eventHandler;
}
void Game::add(std::shared_ptr<sf::Drawable> drawable) {
  this->drawables.push_back(drawable);
}
void Game::start() {
  this->window.setVerticalSyncEnabled(true);
  while (this->window.isOpen()) {
    sf::Event event;
    while (this->window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        this->window.close();
      this->eventHandlerMain(event, this);
    }
    this->window.clear(sf::Color::White);
    for (auto& drawable: this->drawables) {
      this->window.draw(*(drawable.get()));
    }
    this->window.display();
  }
}
