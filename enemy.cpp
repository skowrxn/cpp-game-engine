#include "enemy.h"

bool Enemy::shouldIMoveThisTime() const
{   /// you can change the function
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastMoveTime_);
    return elapsedTime >= moveInterval_;
}
