#include <iostream>
#include "Game.hpp"
#include "AssetManager.hpp"
void eventHandler(sf::Event event, Game* game) {

}

int main() {
  std::cout << "Hello, World!" << std::endl;
  auto circlePtr = std::make_shared<sf::CircleShape>(sf::CircleShape(50.f));
  auto circle = circlePtr.get();
  circle->setFillColor(sf::Color::Yellow);
  loadStandardAssets();
  auto backgroundPtr = std::make_shared<sf::Sprite>(createSprite("background"));
  backgroundPtr->setScale(30.f, 30.f);
  Game game;
  game.add(backgroundPtr);
  game.add(circlePtr);
  game.setMainEventHandler(eventHandler);
  game.start();
  return 0;
}
