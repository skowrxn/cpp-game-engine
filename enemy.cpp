#include "enemy.h"

bool Enemy::shouldIMoveThisTime() const
{   /// you can change the function
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastMoveTime_);
    return elapsedTime >= moveInterval_;
}

int Enemy::lifePercent() const {
    return (this->lifePointsLeft / this->maxLifePoints)*100;
}

bool Enemy::isAlive() const {
    return this->lifePointsLeft > 0;
}

void Enemy::decreaseLife(const int damage) {
    this->lifePointsLeft -= damage;
}
