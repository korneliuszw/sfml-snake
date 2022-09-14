//
// Created by kawuwu on 9/12/22.
//

#ifndef SFML_SNAKE_SRC_GAME_HPP_
#define SFML_SNAKE_SRC_GAME_HPP_
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 400
#define NAME "Snake Plisskin"
#include <SFML/Window.hpp>
#include <functional>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class Game;

typedef std::function<void(sf::Event, Game*)> EventHandler;

class Game {
 private:
  sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), NAME, sf::Style::Default);
  EventHandler eventHandlerMain;
  std::vector<std::shared_ptr<sf::Drawable>> drawables;
 public:
  void add(std::shared_ptr<sf::Drawable>);
  void setMainEventHandler(EventHandler);
  void start();
};

#endif //SFML_SNAKE_SRC_GAME_HPP_
