#ifdef USE_SFML
#include "SFMLRenderer.h"
#include <stdexcept>

namespace si {

SFMLRenderer::SFMLRenderer(int w, int h)
    : _window{ sf::VideoMode({ unsigned(w*16), unsigned(h*16) }),
               "Space Invaders",
               sf::Style::Titlebar | sf::Style::Close }
{
    _window.setVerticalSyncEnabled(true);

    if (!_font.openFromFile("/System/Library/Fonts/Monaco.ttf"))
        throw std::runtime_error("Не удалось открыть шрифт Monaco.ttf");

    for (char c : {'A','V','|','!','*'}) cached(c);
}

// кэш квадратов
sf::RectangleShape& SFMLRenderer::cached(char c)
{
    if (auto it = _cache.find(c); it != _cache.end()) return it->second;

    sf::RectangleShape s({14.f,14.f});
    switch (c) {
        case 'A': s.setFillColor(sf::Color::Green); break;
        case 'V': s.setFillColor(sf::Color::Red);   break;
        case '|':
        case '!': s.setFillColor(sf::Color::Yellow); break;
        default : s.setFillColor(sf::Color::White);
    }
    return _cache[c] = s;
}

void SFMLRenderer::pollEvents(bool& running, bool& /*pause*/)
{
    while (auto ev = _window.pollEvent()) {
        const sf::Event& e = *ev;

        if (e.is<sf::Event::Closed>()) {
            running = false;
            _window.close();
        }
        else if (e.is<sf::Event::KeyPressed>()) {
            const auto* kp = e.getIf<sf::Event::KeyPressed>();
            if (!kp) continue;

            auto key = kp->code;
            if (key == sf::Keyboard::Key::Escape ||
                key == sf::Keyboard::Key::Q)
            {
                running = false;
                _window.close();
            }
        }
    }
}


} // namespace si
#endif // USE_SFML
