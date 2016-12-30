#include <Game.hpp>
#include <Level.hpp>
#include <Platform.hpp>
#include <PhysicalGameObject.hpp>
#include <iostream>

void PhysicalGameObject::Update(float elapsedTime) {
  (void)elapsedTime;
  Level currentLevel = Game::GetLevel();
  std::vector<Platform*> platforms = currentLevel.GetPlatforms();
  std::vector<Platform*>::iterator itr = platforms.begin();

  while (itr != platforms.end()) {
    sf::Rect<float> bounds = GetBoundingRect();
    sf::Rect<float> bottom(bounds.left, bounds.top + bounds.height - 2,
                           bounds.width, 2);

    if ((*itr)->GetCollisionRect().intersects(bottom)) {
      physicState = WALKING;
      return;
    }
    itr++;
  }
  GetSprite().move(0, PhysicalGameObject::gravity * elapsedTime);
  physicState = FALLING;
}