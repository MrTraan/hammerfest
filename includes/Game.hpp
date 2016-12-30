#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <GameObjectManager.hpp>
#include <Level.hpp>

class Game {
 public:
  static void Start();
  static sf::RenderWindow& GetWindow();
  static Level& GetLevel();
  // const static sf::Event GetInput();
  const static int WIN_WIDTH = 420;
  const static int WIN_HEIGHT = 540;

 private:
  static sf::RenderWindow _mainWindow;
  static GameObjectManager _gameObjectManager;
  static Level _currentLevel;
};
