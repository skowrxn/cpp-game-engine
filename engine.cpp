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

    Position p =  Position(middleX, middleY);
    Player player = Player(p, Direction::RIGHT);
    this->player_ = player;
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

void Engine::movePlayerUp() {
    this->player_.moveUp();
}

void Engine::movePlayerDown() {
    this->player_.moveDown();
}

void Engine::movePlayerLeft() {
    this->player_.moveLeft();
}
void Engine::movePlayerRight() {
    this->player_.moveRight();
}

void Engine::playerShoots()
{
    int x = this->playerPosition().x();
    int y = this->playerPosition().y();
    switch (this->playerDirection()) {
        case Direction::UP:
            ++y;
            break;
        case Direction::DOWN:
            --y;
            break;
        case Direction::LEFT:
            --x;
            break;
        case Direction::RIGHT:
            ++x;
            break;
        case Direction::UPPER_LEFT:
            --x;
            ++y;
            break;
        case Direction::UPPER_RIGHT:
            ++x;
            ++y;
            break;
        case Direction::DOWNER_LEFT:
            --y;
            --x;
            break;
        case Direction::DOWNER_RIGHT:
            ++x;
            --y;
            break;
        default:
            break;
    }
    this->bullets_.emplace_back(this->playerDirection(), Position(x,y));
}

Position Engine::playerPosition() const
{
    return this->player_.position();
}

Direction Engine::playerDirection() const
{
    return this->player_.direction();
}

bool Engine::isPlayerAlive() const
{
    return this->player_.isAlive();
}

std::size_t Engine::stageWidthCells() const
{
    return this->stage_.width();
}
std::size_t Engine::stageHeightCells() const
{
    return this->stage_.height();
}

void Engine::randEnemies(Position (*positionGenerator)(int,int))
{
    if (enemies_.size() < maxEnemies_)
    {
        enemies_.push_back(std::make_shared<Enemy>(positionGenerator(stage_.width(), stage_.height()), 100));
    }
}
