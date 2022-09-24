//
// Created by kawuwu on 9/12/22.
//

#include "Game.hpp"
#include "AppleManager.hpp"
#include "Snake.hpp"
#include "ScoreText.hpp"
#include "GameOverText.hpp"
#include "Highscores.hpp"
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
      entity.second->update(clock.getElapsedTime(), this);
      entity.second->draw(&this->window);
    }
    this->window.display();
    clock.restart();
  }
}
void Game::addEntity(std::pair<std::string, std::shared_ptr<Entity>> entity) {
  this->responsiveEntities.insert(entity);
}
void Game::addScore(int points) {
  this->score += points;
}
int Game::getScore() {
  return this->score;
}
bool Game::died() {
  return this->isDead;
}
void Game::die() {
  Highscores::GetInstance()->pushScore(this->score);
  this->isDead = true;
}
void Game::reset() {
  this->isDead = false;
  this->score = false;
  this->responsiveEntities.clear();
  AppleManager::GetInstance()->reset();
  populateGame(this);
}

void populateGame(Game *game) {
  auto apples = AppleManager::GetInstance();
  auto snake = std::make_shared<Snake>();
  auto scoreText = std::make_shared<ScoreText>();
  auto gameOverText = std::make_shared<GameOverText>(&game->window);
  game->addEntity({ "player", snake});
  game->addEntity({"apples", apples});
  game->addEntity({ "score", scoreText });
  game->addEntity({ "gameOver", gameOverText });
}
