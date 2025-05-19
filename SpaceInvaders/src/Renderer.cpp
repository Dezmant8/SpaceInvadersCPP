#include "Renderer.h"

namespace si {

Renderer::Renderer(int w, int h) : _w{w}, _h{h}
{
    initscr();
    cbreak();             // делает getch() немедленным
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    if (LINES < h + 2 || COLS < w + 2) {
        endwin();
        throw std::runtime_error("Терминал слишком маленький.");
    }
}

Renderer::~Renderer()
{
    endwin();
}

} // namespace si
