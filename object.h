#ifndef OBJECT_H
#define OBJECT_H

#include "position.h"

enum class ObjectType
{
    OBJECT_PLAYER,
    OBJECT_BULLET,
    OBJECT_ENEMY,
    OBJECT_WALL,
    OBJECT_UNKNOWN
};


class Object{

    Position position_;
    ObjectType object_type_;

public:
    explicit Object(const ObjectType& object_type, Position position = Position(0,0));
    Position position() const;
    ObjectType type() const;

    void setPosition(const Position& position);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
protected:

};


#endif // OBJECT_H
