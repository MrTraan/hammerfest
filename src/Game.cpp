#include <Game.hpp>
#include <Player.hpp>
#include <Level.hpp>

void Game::Start() {
  _mainWindow.create(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT, 32), "Hammerfest");

  _mainWindow.setFramerateLimit(60);

  Player* p1 = new Player();
  _gameObjectManager.Add("Player", p1);
  p1->SetPosition(WIN_WIDTH / 2, WIN_HEIGHT / 4);

  while (_mainWindow.isOpen()) {
    sf::Event event;
    while (_mainWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        _mainWindow.close();
    }

    _mainWindow.clear(sf::Color::Black);
    _gameObjectManager.UpdateAll();
    _currentLevel.Draw(_mainWindow);
    _gameObjectManager.DrawAll(_mainWindow);
    _mainWindow.display();
  }
}

sf::RenderWindow& Game::GetWindow() {
  return _mainWindow;
}

Level& Game::GetLevel() {
  return _currentLevel;
}

sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;
Level Game::_currentLevel;
