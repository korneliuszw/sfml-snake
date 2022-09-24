#include <iostream>
#include "Game.hpp"
#include "AssetManager.hpp"
#include "Snake.hpp"
#include "AppleManager.hpp"
#include "ScoreText.hpp"

void eventHandler(sf::Event event, Game* game) {
  if (event.type != sf::Event::EventType::KeyReleased && event.key.code == sf::Keyboard::R) {
    game->reset();
  }
  for (auto& entity: game->responsiveEntities)
    entity.second->handleEvent(event);
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  auto circlePtr = std::make_shared<sf::CircleShape>(sf::CircleShape(50.f));
  auto circle = circlePtr.get();
  circle->setFillColor(sf::Color::Yellow);
  loadStandardAssets();
  Game game;
  for (int y = 0; y < TILES_HEIGHT; y++) {
    for (int x = 0; x < TILES_WIDTH; x++) {
      auto pos = tileToReal(sf::Vector2f{(float) x, (float) y});
      auto backgroundPtr = std::make_shared<sf::Sprite>(createSprite("background"));
      backgroundPtr->setPosition(pos);
      game.add(backgroundPtr);
    }
  }
  game.add(circlePtr);
  populateGame(&game);
  game.setMainEventHandler(eventHandler);
  game.start();
  return 0;
}
