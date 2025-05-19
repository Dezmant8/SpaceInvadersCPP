/**
 * @file Input.h
 * @brief Универсальный ввод: ncurses + (опционально) SFML
 */
#ifndef INPUT_H
#define INPUT_H

#include <optional>
#include <curses.h>

#ifdef USE_SFML
    #include <SFML/Window/Keyboard.hpp>
#endif

namespace si {

// действия игры
enum class Action { None, MoveLeft, MoveRight, Shoot, Quit, Pause };

/**
 * @class Input
 * @brief Статическая обёртка, возвращающая одно действие за кадр
 *
 * Алгоритм:
 *   1. Сначала проверка ncurses::getch()
 *   2. Если ничего не пришло и собрано с USE_SFML, опрашиваем
 *      текущее состояние клавиш sf::Keyboard (Left, Right, Space, Q, P)
 */
class Input {
public:
    static Action poll();
};

} // namespace si
#endif // INPUT_H
