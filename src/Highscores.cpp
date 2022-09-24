//
// Created by kaw on 9/24/22.
//

#define HIGHSCORE_FILE "scores.txt"
#define MAX_SCORE_COUNT 5
#include "Highscores.hpp"

Highscores::Highscores() {
  std::ifstream input;
  input.open(HIGHSCORE_FILE);
  int score;
  while (input >> score) {
    this->scores.insert(score);
  }
}
void Highscores::pushScore(int score) {
  if (this->scores.size() < MAX_SCORE_COUNT) {
    this->scores.insert(score);
    update();
    return;
  }
  else if (score > *this->scores.begin()) {
    this->scores.erase(this->scores.begin());
    this->scores.insert(score);
    update();
  }
}
void Highscores::update() {
  std::ofstream file(HIGHSCORE_FILE);
  for (auto score: this->scores) {
    file << score << "\n";
  }
  file.close();
}
Highscores *Highscores::GetInstance() {
  if (!singleton)
    singleton = new Highscores();
  return singleton;
}
Highscores* Highscores::singleton = nullptr;
std::multiset<int> Highscores::getScores() {
  return this->scores;
}
