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


Engine::Engine(std::size_t stageWidth, std::size_t stageHeight)
    : stage_(stageWidth, stageHeight),
      player_(Position(stage_.width() / 2, stage_.height() / 2), Direction::UP)
{

}

void Engine::update()
{
    updateBullets();
    updateEnemies();
    randEnemies();
}

void Engine::updateBullets() const {
    for (auto it = bullets_.begin(); it != bullets_.end();) {
        auto bullet = *it;
        switch (bullet.direction()) {
            case Direction::UP:
                bullet.moveUp();
                break;
            case Direction::DOWN:
                bullet.moveDown();
                break;
            case Direction::LEFT:
                bullet.moveLeft();
                break;
            case Direction::RIGHT:
                bullet.moveRight();
                break;
            case Direction::UPPER_LEFT:
                bullet.moveUp();
                bullet.moveLeft();
                break;
            case Direction::UPPER_RIGHT:
                bullet.moveUp();
                bullet.moveRight();
                break;
            case Direction::DOWNER_LEFT:
                bullet.moveDown();
                bullet.moveLeft();
                break;
            case Direction::DOWNER_RIGHT:
                bullet.moveDown();
                bullet.moveRight();
                break;
            default:
                break;
        }

        for (auto& enemy : enemies_) {
            if (bullet.position() == enemy->position()) {
                enemy->decreaseLife(1);
            }
        }

        if (!stage_.isInside(bullet.position())) {
        }

    }
}

void Engine::updateEnemies()
{
    for (auto it = enemies_.begin(); it != enemies_.end();) {
        auto enemy = *it;
        if (!enemy->isAlive()) {
            enemies_.erase(it);
            delete enemy;
        }
    }
}

void Engine::movePlayerUp() const {
    this->playerPosition().moveUp();
}

void Engine::movePlayerDown() const {
    this->playerPosition().moveDown();
}

void Engine::movePlayerLeft() const {
     this->playerPosition().moveLeft();
}
void Engine::movePlayerRight() const {
    this->playerPosition().moveRight();
}

void Engine::playerShoots()
{
    this->bullets_.emplace_back(this->playerDirection(), this->playerPosition());
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
        enemies_.push_back(Enemy(std::make_shared<Enemy>(positionGenerator(stage_.width(), stage_.height()))));
    }
}
