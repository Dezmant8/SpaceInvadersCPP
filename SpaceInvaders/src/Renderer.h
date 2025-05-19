/**
 * @file Renderer.h
 * @brief Терминальный рендерер (ncurses).
 */
#ifndef RENDERER_H
#define RENDERER_H

#include <curses.h>
#include <vector>
#include <memory>

#include "Entity.h"
#include "Player.h"

namespace si {

    class Renderer {
    public:
        Renderer(int width, int height);
        ~Renderer();

        // Полный вывод кадра
        template <typename Container>
        void drawFrame(const Container& objects,
                       const Player&    player,
                       int score, int lives,
                       int wave, bool paused);

        int width()  const noexcept { return _w; }
        int height() const noexcept { return _h; }

    private:
        int _w, _h;
    };

    template <typename Container>
    void Renderer::drawFrame(const Container& objs,
                             const Player& player,
                             int score, int lives,
                             int wave, bool paused)
    {
        erase();    // очистка
        box(stdscr, 0, 0);  // рамка

        // HUD-строка
        mvprintw(0, 2, " Score: %d  Lives: %d  Wave: %d ",
                 score, lives, wave);
        if (paused)
            mvprintw(0, _w - 10, "[PAUSE]");

        // отрисовка всех объектов (пули, враги, взрывы ...)
        for (const auto& ptr : objs) {
            if (!ptr->alive()) continue;
            mvaddch(ptr->y() + 1, ptr->x() + 1, ptr->symbol());
        }

        // отдельная отрисовка игрока (его нет в _objects)
        mvaddch(player.y() + 1, player.x() + 1, player.symbol());

        refresh();  // вывод на экран
    }

} // namespace si

#endif // RENDERER_H
