/**
 * @file Entity.h
 * @brief Базовый класс для всех объектов игры. Содержит
 *        общие координаты, размеры и символ для отрисовки.
 */
#ifndef ENTITY_H
#define ENTITY_H

#include <cstdint>

/**
 * @brief Пространство имён для игры.
 */
namespace si {   // Space Invaders
    /**
     * @class Entity
     * @brief Абстрактная сущность: всё, у чего есть положение на экране.
     * напрямую экземпляров Entity быть не должно —
     * только наследники (Player, Enemy, Bullet, Explosion).
     */
    class Entity {
    public:
        /// Конструктор: принимает исходные координаты и символ
        Entity(int x, int y, char symbol, uint8_t width = 1, uint8_t height = 1)
            : _x{x}, _y{y}, _symbol{symbol}, _w{width}, _h{height}, _alive{true} {}

        /// Виртуальный деструктор для корректного удаления наследников
        virtual ~Entity() = default;

        // ----- Геттеры ------------------------------------------------------
        int x()      const noexcept { return _x;      }
        int y()      const noexcept { return _y;      }
        uint8_t w()  const noexcept { return _w;      }
        uint8_t h()  const noexcept { return _h;      }
        char symbol()const noexcept { return _symbol; }
        bool alive() const noexcept { return _alive;  }

        // ----- Сет-методы ---------------------------------------------------
        void setPos(int x, int y) noexcept { _x = x; _y = y; }
        void kill()            noexcept { _alive = false;    }

        /**
         * @brief Чисто виртуальный метод обновления.
         * @param dt Время (в секундах) с момента прошлого кадра;
         *           позволяет делать движение независимым от FPS.
         */
        virtual void update(double dt) = 0;

    protected:
        int _x, _y;             ///< Левый-верхний угол спрайта
        char _symbol;           ///< Символ, отображаемый в терминале
        uint8_t _w, _h;         ///< Ширина и высота спрайта
        bool _alive;            ///< Флаг жив
    };
} // namespace si

#endif // ENTITY_H