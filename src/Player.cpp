#include <cassert>
#include <Game.hpp>
#include <Player.hpp>
#include <iostream>

Player::Player() {
  Load("assets/images/igor.png");
  assert(IsLoaded());

  GetSprite().setOrigin(0, 0);
}

Player::~Player() {}

void Player::Draw(sf::RenderWindow& rw) {
  VisibleGameObject::Draw(rw);
}

void Player::Update(float elapsedTime) {
  PhysicalGameObject::Update(elapsedTime);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
    _velocity.x = -150.0f;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
    _velocity.x = 150.0f;
  } else {
    _velocity.x = 0.0f;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) &&
      physicState != FALLING) {
    physicState = FALLING;
    _velocity.y = -500.0f;
  } else if (_velocity.y < 0.0f) {
    _velocity.y /= 1.1f;
  }

  if (_velocity.y > -10.0f && _velocity.y < 0.0f) {
    _velocity.y = 0.0f;
  }

  if (physicState == WALKING) {
    _velocity.y = 0.0f;
  }
  GetSprite().move(_velocity.x * elapsedTime, _velocity.y * elapsedTime);
}
