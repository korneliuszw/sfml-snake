//
// Created by kawuwu on 9/12/22.
//

#include "AssetManager.hpp"
#include "Snake.hpp"
#include "AppleManager.hpp"

void AssetManager::loadTexture(const std::string& resourceName, const std::string& resourcePath) {
  sf::Texture* texture = new sf::Texture();
  texture->loadFromFile(resourcePath);
  assets.textures.insert({resourceName, texture});
}
sf::Texture *AssetManager::getTexture(const std::string& resourceName) {
  return assets.textures.at(resourceName);
}
AssetManager::~AssetManager() {
  for (auto& v: assets.textures) {
    delete v.second;
  }
}
AssetManager *AssetManager::GetInstance() {
  if (singleton == nullptr)
    singleton = new AssetManager();
  return singleton;
}

sf::Sprite createSprite(const std::string& resourceName) {
  sf::Texture* texture = AssetManager::GetInstance()->getTexture(resourceName);
  texture->setRepeated(true);
  sf::Sprite sprite;
  sprite.setTexture(*texture);
  return sprite;
}
void loadStandardAssets() {
  auto manager = AssetManager::GetInstance();
  manager->loadTexture("background", "assets/Grass/Grass11.png");
  manager->loadTexture(TAIL_RESOURCE, "assets/tail_down.png");
  manager->loadTexture(HEAD_RESOURCE, "assets/head_up.png");
  manager->loadTexture(ANGLE_BODY_RESOURCE, "assets/body_topleft.png");
  manager->loadTexture(BODY_STRAIGHT_RESOURCE, "assets/body_vertical.png");
  manager->loadTexture(APPLE_RESOURCE, "assets/apple.png");
}
AssetManager* AssetManager::singleton = nullptr;