//
// Created by kawuwu on 9/12/22.
//

#include "Snake.hpp"
#include <AssetManager.hpp>
void SnakePart::updateSprite() {
  if (this->next == nullptr) {
    if (this->previous == nullptr)
      this->sprite = createSprite(HEAD_RESOURCE);
    else this->sprite = createSprite(TAIL_RESOURCE);
  }
}
