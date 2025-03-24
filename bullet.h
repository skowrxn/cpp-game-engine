#ifndef BULLET_H
#define BULLET_H

#include "object.h"
#include "direction.h"

class Bullet : public Object
{
    Direction direction_;
    static constexpr int speed_ = 2;

public:
    Bullet(const Direction& direction, const Position& startPosition) : Object(ObjectType::OBJECT_BULLET, startPosition), direction_(direction) {};
    Direction direction() const {
        return this->direction_;
    }
    void setDirection(const Direction& direction) {
        this->direction_ = direction;
    }

    static int speed() {
        return speed_;
    }

};

#endif // BULLET_H
