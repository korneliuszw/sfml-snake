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
//  this->window.setFramerateLimit(60);
  sf::Clock clock;
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
    for (auto& entity: this->responsiveEntities) {
      entity.second->update(clock.getElapsedTime());
      entity.second->draw(&this->window);
    }
    this->window.display();
    clock.restart();
  }
}
void Game::addEntity(std::pair<std::string, std::shared_ptr<Entity>> entity) {
  this->responsiveEntities.insert(entity);
}
