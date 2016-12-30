#pragma once
#include <PhysicalGameObject.hpp>

class Player : public PhysicalGameObject {
 public:
  Player();
  ~Player();

  void Update(float elapsedTime);
  void Draw(sf::RenderWindow& rw);
};
