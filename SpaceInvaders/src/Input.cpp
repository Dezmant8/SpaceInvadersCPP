#include "Input.h"
#include <cctype>

namespace si {

struct KeyEdge { bool prev = false; };
static KeyEdge p_nc, q_nc;                 // терминал

#ifdef USE_SFML
static KeyEdge l_s,r_s,sp_s,esc_s,q_s,p_s; // sfml
#endif

static bool edge(KeyEdge& k, bool now)
{
    bool e = now && !k.prev;
    k.prev = now;
    return e;
}

Action Input::poll()
{
    // ncurses
    int ch = getch();
    if (ch == KEY_LEFT)  return Action::MoveLeft;
    if (ch == KEY_RIGHT) return Action::MoveRight;
    if (ch == ' ')       return Action::Shoot;

    if (edge(p_nc, ch=='p'||ch=='P')) return Action::Pause;
    if (edge(q_nc, ch=='q'||ch=='Q')) return Action::Quit;

#ifdef USE_SFML
    using K = sf::Keyboard::Key;

    if (edge(l_s,   sf::Keyboard::isKeyPressed(K::Left)))   return Action::MoveLeft;
    if (edge(r_s,   sf::Keyboard::isKeyPressed(K::Right)))  return Action::MoveRight;
    if (edge(sp_s,  sf::Keyboard::isKeyPressed(K::Space)))  return Action::Shoot;
    if (edge(esc_s, sf::Keyboard::isKeyPressed(K::Escape))) return Action::Quit;
    if (edge(q_s,   sf::Keyboard::isKeyPressed(K::Q)))      return Action::Quit;
    if (edge(p_s,   sf::Keyboard::isKeyPressed(K::P)))      return Action::Pause;
#endif

    return Action::None;
}

} // namespace si
