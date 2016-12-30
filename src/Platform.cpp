#include <Platform.hpp>
#include <cassert>

Platform::Platform(std::string theme) {
  Load("./assets/images/levels/" + theme + ".png");

  assert(IsLoaded());
}

sf::Rect<float> Platform::GetCollisionRect() {
  sf::Rect<float> spriteBounds = GetBoundingRect();

  sf::Rect<float> _collisionRect(spriteBounds.left, spriteBounds.top,
                                 spriteBounds.width, 1);
  return _collisionRect;
}
