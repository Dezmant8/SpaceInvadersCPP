/**
 * @file main.cpp
 * @brief Точка входа. Создаёт объект Game и запускает run().
 *
 * main.cpp маленький, вся логика в классах.
 */
#include "Game.h"
#include <exception>
#include <iostream>

int main()
{
    try {
        si::Game game;  // размеры по умолчанию 40×25
        game.run();
    } catch (const std::exception& ex) {
        // Если произошло исключение (например, маленький терминал)
        // вывод сообщения уже после закрытия ncurses
        std::cerr << "Fatal error: " << ex.what() << '\n';
        return 1;
    }
    return 0;
}
