#include <iostream>
#include "Game.hpp"
#include "AssetManager.hpp"
#include "Snake.hpp"
#include "AppleManager.hpp"

void eventHandler(sf::Event event, Game* game) {
  for (auto& entity: game->responsiveEntities)
    entity.second->handleEvent(event);
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  auto circlePtr = std::make_shared<sf::CircleShape>(sf::CircleShape(50.f));
  auto circle = circlePtr.get();
  circle->setFillColor(sf::Color::Yellow);
  loadStandardAssets();
  auto apples = AppleManager::GetInstance();
  auto backgroundPtr = std::make_shared<sf::Sprite>(createSprite("background"));
  backgroundPtr->setScale(30.f, 30.f);
  auto snake = std::make_shared<Snake>();
  Game game;
  game.add(backgroundPtr);
  game.add(circlePtr);
  game.addEntity({ "player", snake});
  game.addEntity({"apples", apples});

  game.setMainEventHandler(eventHandler);
  game.start();
  return 0;
}
