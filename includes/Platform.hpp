#pragma once

#include <iostream>
#include <VisibleGameObject.hpp>

class Platform : public VisibleGameObject {
 public:
  Platform(std::string theme);
  sf::Rect<float> GetCollisionRect();
};