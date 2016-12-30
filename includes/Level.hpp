#pragma once

#include <VisibleGameObject.hpp>
#include <Platform.hpp>

class Level : public VisibleGameObject {
 public:
  Level();
  std::vector<Platform*> GetPlatforms();
  void Draw(sf::RenderWindow& rw);

 private:
  int depth;
  std::vector<Platform*> _platforms;
};