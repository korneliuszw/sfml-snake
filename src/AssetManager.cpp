//
// Created by kawuwu on 9/12/22.
//

#include "AssetManager.hpp"
void AssetManager::loadTexture(std::string resourceName, std::string resourcePath) {
  sf::Texture* texture = new sf::Texture();
  texture->loadFromFile(resourcePath);
  assets.textures.insert({resourceName, texture});
}
sf::Texture *AssetManager::getTexture(std::string resourceName) {
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

sf::Sprite createSprite(std::string resourceName) {
  sf::Texture* texture = AssetManager::GetInstance()->getTexture(resourceName);
  texture->setRepeated(true);
  sf::Sprite sprite;
  sprite.setTexture(*texture);
  return sprite;
}
void loadStandardAssets() {
  AssetManager::GetInstance()->loadTexture("background", "assets/Grass/Grass11.png");
}
AssetManager* AssetManager::singleton = nullptr;