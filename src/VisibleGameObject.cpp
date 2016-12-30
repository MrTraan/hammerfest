#include <VisibleGameObject.hpp>

VisibleGameObject::VisibleGameObject() : _isLoaded(false) {}

VisibleGameObject::~VisibleGameObject() {}

void VisibleGameObject::Load(std::string filename) {
  if (!_texture.loadFromFile(filename)) {
    _filename = "";
    _isLoaded = false;
  } else {
    _filename = filename;
    _sprite.setTexture(_texture);
    _isLoaded = true;
  }
}

void VisibleGameObject::Draw(sf::RenderWindow& renderWindow) {
  if (_isLoaded)
    renderWindow.draw(_sprite);
}

void VisibleGameObject::Update(float elapsedTime) {
  (void)elapsedTime;
}

sf::Vector2f VisibleGameObject::GetPosition() const {
  if (_isLoaded)
    return _sprite.getPosition();
  return sf::Vector2f();
}

sf::Sprite& VisibleGameObject::GetSprite() {
  return _sprite;
}

void VisibleGameObject::SetPosition(float x, float y) {
  if (_isLoaded)
    _sprite.setPosition(x, y);
}

bool VisibleGameObject::IsLoaded() const {
  return _isLoaded;
}

float VisibleGameObject::GetHeight() const {
  return _sprite.getLocalBounds().height;
}

float VisibleGameObject::GetWidth() const {
  return _sprite.getLocalBounds().width;
}

sf::Rect<float> VisibleGameObject::GetBoundingRect() const {
  return _sprite.getGlobalBounds();
}

sf::Rect<float> VisibleGameObject::GetCollisionRect() {
  return _sprite.getGlobalBounds();
}
