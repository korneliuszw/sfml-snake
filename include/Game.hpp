//
// Created by kawuwu on 9/12/22.
//

#ifndef SFML_SNAKE_SRC_GAME_HPP_
#define SFML_SNAKE_SRC_GAME_HPP_
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400

#define TILES_WIDTH 32
#define TILES_HEIGHT 25

constexpr float TILE_WIDTH = WINDOW_WIDTH / TILES_WIDTH;
constexpr float TILE_HEIGHT = WINDOW_HEIGHT / TILES_HEIGHT;

#define NAME "Snake Plisskin"
#include <SFML/Window.hpp>
#include <functional>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Game;

typedef std::function<void(sf::Event, Game*)> EventHandler;

class Game {
 private:
  sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), NAME, sf::Style::Default);
  EventHandler eventHandlerMain;
  std::vector<std::shared_ptr<sf::Drawable>> drawables;
 public:
  std::unordered_map<std::string, std::shared_ptr<Entity>> responsiveEntities;
  void addEntity(std::pair<std::string, std::shared_ptr<Entity>>);
  void add(std::shared_ptr<sf::Drawable>);
  void setMainEventHandler(EventHandler);
  void start();
};
template <class T>
sf::Vector2f tileToReal(sf::Vector2<T> position) {
  return { position.x * TILE_WIDTH, position.y * TILE_HEIGHT };
}

#endif //SFML_SNAKE_SRC_GAME_HPP_
