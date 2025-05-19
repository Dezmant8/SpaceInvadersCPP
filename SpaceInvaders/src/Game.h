#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Explosion.h"
#include "Renderer.h"
#ifdef USE_SFML
#include "SFMLRenderer.h"
#endif
#include "Input.h"

#include <vector>
#include <memory>
#include <chrono>

namespace si {

class Game {
public:
    explicit Game(int width = 40, int height = 25);
    void run();

private:
    // логика
    void update(double dt);
    void spawnWave();
    void nextWave();
    void handleCollisions();
    void moveFleet(double dt);

    // размеры поля
    const int _w, _h;

    // игровые сущности
    Player _player;
    std::vector<std::unique_ptr<Entity>> _objects;

    // параметры волны
    int    _level        {1};
    int    _dir          {1};        // +1 → вправо, −1 → влево
    double _fleetX       {0.0};      // накопительная дробь сдвига
    double _fleetSpeed   {2.0};      // базовая скорость армии
    double _shootTimer   {0.0};      // накопитель времени выстрела
    double _shootPeriod  {1.5};      // интервал между выстрелами

    // рендер
    Renderer _renderer;
#ifdef USE_SFML
    SFMLRenderer _sfml;
#endif

    // состояние
    bool _running{true};
    bool _paused {false};
    std::chrono::steady_clock::time_point _last;
};

} // namespace si
#endif
