/**
 * @file Explosion.h
 * @brief Короткая «анимация» взрыва
 */
#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Entity.h"

namespace si {

class Explosion final : public Entity {
public:
    Explosion(int x, int y)
        : Entity(x, y, '*')
        , _timeLeft{0.3}
        , _total{0.3} {}

    void update(double dt) override {
        _timeLeft -= dt;
        if (_timeLeft <= 0.0) _alive = false;
    }

    // 1.0 → 0.0
    double progress() const noexcept { return _timeLeft / _total; }

private:
    double _timeLeft;
    const double _total;
};

} // namespace si
#endif
