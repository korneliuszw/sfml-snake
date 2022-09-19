#include <iostream>
#include "Game.hpp"
#include "AssetManager.hpp"
#include "Snake.hpp"

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
  auto backgroundPtr = std::make_shared<sf::Sprite>(createSprite("background"));
  backgroundPtr->setScale(30.f, 30.f);
  auto snake = std::make_shared<Snake>();
  Game game;
//  game.add({"background", backgroundPtr});
  game.add(circlePtr );
  game.addEntity({ "player", snake});
  game.setMainEventHandler(eventHandler);
  game.start();
  return 0;
}
