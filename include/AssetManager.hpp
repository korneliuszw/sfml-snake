//
// Created by kawuwu on 9/12/22.
//

#ifndef SFML_SNAKE_SRC_ASSETMANAGER_HPP_
#define SFML_SNAKE_SRC_ASSETMANAGER_HPP_

#include <unordered_map>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class AssetManager {
 private:
  class Assets {
   public:
    std::unordered_map<std::string, sf::Texture*> textures;
  };
  Assets assets;
  static AssetManager* singleton;
 public:
  void loadTexture(std::string resourceName, std::string resourcePath);
  sf::Texture* getTexture(std::string resoureName);
  ~AssetManager();
 public:
  static AssetManager* GetInstance();
};

void loadStandardAssets();

sf::Sprite createSprite(std::string resourceName);

#endif //SFML_SNAKE_SRC_ASSETMANAGER_HPP_
