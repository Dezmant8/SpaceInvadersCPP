#ifndef SFML_RENDERER_H
#define SFML_RENDERER_H

#ifdef USE_SFML
#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "Entity.h"
#include "Player.h"
#include "Explosion.h"

namespace si {

class SFMLRenderer {
public:
    SFMLRenderer(int width, int height);

    template <typename C>
    void drawFrame(const C& objects,
                   const Player& player,
                   int score, int lives,
                   int wave, bool paused);

    bool isOpen() const { return _window.isOpen(); }
    void pollEvents(bool& quit, bool& pause);

private:
    sf::RenderWindow _window;
    sf::Font         _font;

    std::unordered_map<char, sf::RectangleShape> _cache;
    sf::RectangleShape& cached(char symbol);
};

// рамка
template <typename C>
void SFMLRenderer::drawFrame(const C& objs,
                             const Player& pl,
                             int score, int lives,
                             int wave, bool paused)
{
    _window.clear(sf::Color::Black);

    // объекты
    for (const auto& e : objs) {
        if (!e->alive()) continue;

        if (auto* ex = dynamic_cast<const Explosion*>(e.get())) {
            // анимированный взрыв
            float s = 14.f * (1.f + 1.f * (1.0 - ex->progress()));
            sf::CircleShape boom(s / 2.f);
            boom.setFillColor(sf::Color(255, 128, 0));
            boom.setPosition({ e->x() * 16.f + 7.f - s/2.f,
                               e->y() * 16.f + 7.f - s/2.f });
            _window.draw(boom);
        } else {
            auto& sh = cached(e->symbol());
            sh.setPosition({ e->x() * 16.f, e->y() * 16.f });
            _window.draw(sh);
        }
    }

    // игрок
    auto& shp = cached(pl.symbol());
    shp.setPosition({ pl.x() * 16.f, pl.y() * 16.f });
    _window.draw(shp);

    // HUD
    sf::Text hud(_font, "", 18);
    hud.setFillColor(sf::Color::White);
    hud.setString("Score: " + std::to_string(score) +
                  "  Lives: " + std::to_string(lives) +
                  "  Wave: "  + std::to_string(wave) +
                  (paused ? "  [PAUSE]" : ""));
    _window.draw(hud);

    _window.display();
}

} // namespace si
#endif
#endif
