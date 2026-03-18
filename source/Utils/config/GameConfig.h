#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace config {
    // Общее:
    const unsigned int FRAME_RATE_LIMIT = 60;
    // Меню:
    const sf::Vector2f BUTTON_SIZE = { 250, 100 };
    const size_t BUTTON_FONT_SIZE = static_cast<size_t>(BUTTON_SIZE.y / 1.5f);
    const float BUTTON_FRAME_THICKNESS = 2.0f;
    const std::string FONT_FILE = "assets/text.otf";
    const char SELECT_LEVEL_TITLE[] = "Select Level";
    const sf::VideoMode SELECT_LEVEL_VIDEO_MODE ({ 400, 600 });
    const char BUTTON_TEXT_EASY[] = "Easy";
    const char BUTTON_TEXT_MEDIUM[] = "Medium";
    const char BUTTON_TEXT_HARD[] = "Hard";
    const char BUTTON_TEXT_EXIT[] = "Exit";
    // Игра:
    const sf::VideoMode GAME_VIDEO_MODE({ 1080, 720 });
    const char EASY_GAME_TITLE[] = "Level: Easy";
    const char MEDIUM_GAME_TITLE[] = "Level: Medium";
    const char HARD_GAME_TITLE[] = "Level: Hard";
    const float EASY_GAME_ENEMY_RATIO = 0.0f;
    const float MEDIUM_GAME_ENEMY_RATIO = 0.03f;
    const float HARD_GAME_ENEMY_RATIO = 0.07f;
    const float ROOM_SIZE = 50;
    const float GAME_ENEMY_SIZE = ROOM_SIZE * 0.7;
    const float GAME_FOOD_SIZE = ROOM_SIZE * 0.2;
    const float GAME_WIDTH = 800.0f;
    const float GAME_HEIGHT = 600.0f;
    // Пакмэн:
    const float GAME_PACMAN_SIZE = ROOM_SIZE * 0.8;
    const sf::Keyboard::Key KEY_LEFT = sf::Keyboard::Key::A;
    const sf::Keyboard::Key KEY_RIGHT = sf::Keyboard::Key::D;
    const sf::Keyboard::Key KEY_UP = sf::Keyboard::Key::W;
    const sf::Keyboard::Key KEY_DOWN = sf::Keyboard::Key::S;
    // Цвета:
    // const sf::Color BUTTON_COLOR_TEXT{ 0, 0, 0 };
    // const sf::Color BUTTON_COLOR_FILL{ 180, 180, 180 };
    // const sf::Color BUTTON_COLOR_SELECTION{ 255, 180, 180 };
    // const sf::Color BUTTON_COLOR_FRAME{ 0, 0, 0 };
    // const sf::Color SELECT_LEVEL_BACKGROUND_COLOR{ 230,230,230 };
    // const sf::Color GAME_COLOR_BACKGROUND_INGAME{ 230,230,230 };
    // const sf::Color GAME_COLOR_BACKGROUND_WIN{ 0, 255, 0 };
    // const sf::Color GAME_COLOR_BACKGROUND_LOST{ 255, 0, 0 };
    // const sf::Color GAME_COLOR_PACMAN{ 250, 150, 0 };
    // const sf::Color GAME_COLOR_ROOM{ 255, 255, 255 };
    // const sf::Color GAME_COLOR_WALL{ 0, 0, 0 };
    // const sf::Color GAME_FOOD_COLOR{ 0, 200, 100 };
    // const sf::Color GAME_ENEMY_COLOR{ 255, 50, 0 };
    // Меню
    const sf::Color BUTTON_COLOR_TEXT{ 0, 255, 255 };        // неоново-голубой
    const sf::Color BUTTON_COLOR_FILL{ 20, 20, 40 };        // тёмно-синий
    const sf::Color BUTTON_COLOR_SELECTION{ 255, 0, 255 };  // неоново-розовый
    const sf::Color BUTTON_COLOR_FRAME{ 0, 255, 255 };      // неоново-голубой
    const sf::Color SELECT_LEVEL_BACKGROUND_COLOR{ 10, 10, 20 }; // очень тёмный фон

    // Игровой фон (в зависимости от состояния)
    const sf::Color GAME_COLOR_BACKGROUND_INGAME{ 5, 5, 15 };    // почти чёрный с синевой
    const sf::Color GAME_COLOR_BACKGROUND_WIN{ 0, 255, 0 };      // ярко-зелёный (победа)
    const sf::Color GAME_COLOR_BACKGROUND_LOST{ 255, 0, 0 };     // ярко-красный (поражение)

    // Игровые объекты
    const sf::Color GAME_COLOR_PACMAN{ 255, 255, 0 };            // жёлтый (неоновый)
    const sf::Color GAME_COLOR_ROOM{ 30, 30, 50 };               // тёмно-синий для комнат
    const sf::Color GAME_COLOR_WALL{ 0, 255, 255 };              // неоново-голубой для стен
    const sf::Color GAME_FOOD_COLOR{ 255, 105, 180 };            // неоново-розовый (еда)
    const sf::Color GAME_ENEMY_COLOR{ 255, 0, 0 };               // неоново-красный (враги)
    // Позиционирование
    const float BUTTON_SPACING_MULTIPLIER = 1.2f;  // коэффициент расстояния между кнопками
    const float BUTTON_VERTICAL_SPACING = BUTTON_SIZE.y * BUTTON_SPACING_MULTIPLIER;  // расстояние между кнопками
    const float BUTTON_FIRST_Y_OFFSET = 100.0f;  // отступ первой кнопки сверху
    const size_t BUTTON_COUNT = 4;
}
