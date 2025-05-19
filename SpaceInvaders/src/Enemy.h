#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Bullet.h"
#include <memory>

namespace si {

class Enemy : public Entity {
public:
    Enemy(int x,int y) : Entity(x,y,'V') {}

    std::unique_ptr<Bullet> fire()
    {
        return std::make_unique<Bullet>(_x,_y+1,+25,'!');
    }

    void update(double) override {/* движением управляет Game::moveFleet */}
};

} // namespace si
#endif
