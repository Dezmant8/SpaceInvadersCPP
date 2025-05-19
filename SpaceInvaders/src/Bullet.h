#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

namespace si {

class Bullet final : public Entity {
public:
    Bullet(int x, int y, int dy, char symbol = '|') : Entity(x, y, symbol) , _posY{static_cast<double>(y)} , _dy{dy} {}

    void update(double dt) override
    {
        _posY += _dy * dt;
        _y = static_cast<int>(_posY);

        if (_y < 0 || _y > 40)
            _alive = false;
    }

    int velocity() const noexcept { return _dy; }

private:
    double _posY;   //настоящая координата по Y (с плавающей точкой)
    int    _dy;
};

} // namespace si
#endif
