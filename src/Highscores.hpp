//
// Created by kaw on 9/24/22.
//

#ifndef SFML_SNAKE_SRC_HIGHSCORES_HPP_
#define SFML_SNAKE_SRC_HIGHSCORES_HPP_

#include <set>
#include <fstream>
class Highscores {
 private:
  std::multiset<int> scores;
  void update();
  static Highscores* singleton;
 public:
  Highscores();
  std::multiset<int> getScores();
  void pushScore(int score);
  static Highscores* GetInstance();
};

#endif //SFML_SNAKE_SRC_HIGHSCORES_HPP_
