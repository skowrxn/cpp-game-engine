#include <algorithm>
#include "engine.h"
#include "player.h"
#include "stage.h"
#include "bullet.h"
#include "enemy.h"


namespace
{
inline auto signum(int x)
{
    return (x > 0) - (x < 0);
}

Direction randDirection()
{
    auto randEdge = rand() % static_cast<uint8_t>(Direction::UPPER_LEFT);
    return static_cast<Direction>(randEdge);
}
} // namespace


Position generateNewEnemyPosition(int width, int height)
{
    Position position2Generate = Position(rand() % width, rand() % height);

    switch (randDirection()) {
        case Direction::UP:
            position2Generate.y_ = height-1;
            break;
        case Direction::DOWN:
            position2Generate.y_ = 0;
            break;
        case Direction::LEFT:
            position2Generate.x_ = 0;
            break;
        case Direction::RIGHT:
            position2Generate.x_ = width-1;
            break;
        default:
            break;
    }
    return position2Generate;
}


Engine::~Engine() = default;


Engine::Engine(std::size_t stageWidth, std::size_t stageHeight):
    stage_(stageWidth, stageHeight)
{
    const decltype(Position::x_) middleX = stage_.width() / 2;
    const decltype(Position::y_) middleY = stage_.height() / 2;

    // TODO: ...
}

void Engine::update()
{
    updateBullets();
    updateEnemies();
    randEnemies();
}

void Engine::updateBullets()
{
    // TODO: ...
}

void Engine::updateEnemies()
{
    // TODO: ...
}

void Engine::movePlayerUp()
{
    // TODO: ...
}

void Engine::movePlayerDown()
{
    // TODO: ...
}

void Engine::movePlayerLeft()
{
    // TODO: ...
}
void Engine::movePlayerRight()
{
    // TODO: ...
}

void Engine::playerShoots()
{
    // TODO: ...
}

Position Engine::playerPosition() const
{
    // TODO: ...
    return {};
}

Direction Engine::playerDirection() const
{
    // TODO: ...
    return {};
}

bool Engine::isPlayerAlive() const
{
    // TODO: ...
    return {};
}

std::size_t Engine::stageWidthCells() const
{
    // TODO: ...
    return {};
}
std::size_t Engine::stageHeightCells() const
{
    // TODO: ...
    return {};
}

void Engine::randEnemies(Position (*positionGenerator)(int,int))
{
    if (enemies_.size() < maxEnemies_)
    {
        // TODO: ...
    }
}
