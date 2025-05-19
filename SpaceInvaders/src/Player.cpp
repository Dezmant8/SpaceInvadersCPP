#include "Player.h"
#include "Bullet.h"

namespace si {

Player::Player(int x, int y) : Entity(x, y, 'A') {}

void Player::moveLeft()  { if (_x > 0) --_x; }
void Player::moveRight(int maxX) { if (_x < maxX) ++_x; }

bool Player::canShoot() const noexcept { return _cooldown <= 0.0; }

std::unique_ptr<Bullet> Player::shoot()
{
    _cooldown = _fireRate;
    return std::make_unique<Bullet>(_x, _y - 1, -25);
}

void Player::hit() { --_lives; }

void Player::update(double dt)
{
    if (_cooldown > 0.0) _cooldown -= dt;
}

} // namespace si
