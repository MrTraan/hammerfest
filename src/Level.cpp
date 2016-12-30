#include <Game.hpp>
#include <Level.hpp>
#include <cassert>

Level::Level() : depth(0) {
  Load("./assets/images/levels/" + std::to_string(depth) + ".png");
  assert(IsLoaded());

  GetSprite().setOrigin(0, 0);
  SetPosition(0, 0);

  Platform* p = new Platform("green");
  p->SetPosition(-100, Game::WIN_HEIGHT / 2);

  Platform* p2 = new Platform("green");
  p2->SetPosition(0, 2.5f * (Game::WIN_HEIGHT / 4));

  _platforms.push_back(p);
  _platforms.push_back(p2);
}

std::vector<Platform*> Level::GetPlatforms() {
  return _platforms;
}

void Level::Draw(sf::RenderWindow& rw) {
  VisibleGameObject::Draw(rw);

  std::vector<Platform*>::iterator itr;
  itr = _platforms.begin();

  while (itr != _platforms.end()) {
    (*itr)->Draw(rw);
    itr++;
  }
}