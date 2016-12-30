#pragma once

#include <VisibleGameObject.hpp>

class PhysicalGameObject : public VisibleGameObject {
 public:
  PhysicalGameObject() : physicState(FALLING){};
  void Update(float elapsedTime);

  enum ePhysicState { WALKING, FALLING };

  constexpr static float gravity = 150.0f;

 protected:
  sf::Vector2<float> _velocity;
  ePhysicState physicState;
};
