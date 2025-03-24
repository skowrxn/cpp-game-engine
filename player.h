#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "direction.h"

class Player : public Object
{
    Direction direction_;
    bool is_alive_;
public:
    void setDirection(const Direction& direction);
    Direction direction() const;
    bool isAlive() const;
    void setIsAlive(bool alive);

    Player(const Position& startPosition, const Direction& direction) : Object(ObjectType::OBJECT_PLAYER, startPosition), direction_(direction), is_alive_(true) { }
    Player();
};


inline void Player::setDirection(const Direction &direction) {
    this->direction_ = direction;
}

inline Direction Player::direction() const {
    return this->direction_;
}

inline bool Player::isAlive() const {
    return this->is_alive_;
}

inline void Player::setIsAlive(bool alive) {
    this->is_alive_ = alive;
}

inline Player::Player(): Object(ObjectType::OBJECT_PLAYER, Position(0,0)) {
    this->direction_ = Direction::RIGHT;
    this->is_alive_ = true;
}

#endif // PLAYER_H
