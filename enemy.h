#ifndef ENEMY_H
#define ENEMY_H

#include <chrono>
#include "object.h"

class Enemy : public Object {
public:
    explicit Enemy(const Position& position, const int maxLifePoints = 100) : Object(ObjectType::OBJECT_ENEMY, position),
    lifePointsLeft(maxLifePoints), maxLifePoints(maxLifePoints) {};

    int lifePercent() const;

    bool shouldIMoveThisTime() const;

    bool isAlive() const;

    void decreaseLife(int damage);

private:
    static constexpr std::chrono::milliseconds moveInterval_{500};

    mutable std::chrono::steady_clock::time_point lastMoveTime_;

    int lifePointsLeft;

    int maxLifePoints;
};

#endif // ENEMY_H
