#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <memory>

namespace si {

class Bullet;

class Player final : public Entity {
public:
    explicit Player(int x, int y);

    void moveLeft();
    void moveRight(int maxX);

    bool canShoot() const noexcept;
    std::unique_ptr<Bullet> shoot();

    void hit();
    int  lives()  const noexcept { return _lives; }
    void addScore(int v) noexcept { _score += v; }
    int  score()  const noexcept { return _score; }

    void update(double dt) override;   // уменьшает кулдаун

private:
    int    _lives     {3};
    int    _score     {0};
    double _cooldown  {0};
    const  double _fireRate{0.35};
};

} // namespace si
#endif
