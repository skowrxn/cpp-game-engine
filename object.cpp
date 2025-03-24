#include "object.h"

Object::Object(const ObjectType &object_type, const Position position) : position_(position), object_type_(object_type) { }

Position Object::position() const {
    return this->position_;
}

ObjectType Object::type() const {
    return this->object_type_;
}

void Object::setPosition(const Position &position) {
    this->position_ = position;
}

void Object::moveUp() {
    this->position_.moveUp();
}

void Object::moveDown() {
    this->position_.moveDown();
}

void Object::moveLeft() {
    this->position_.moveLeft();
}

void Object::moveRight() {
    this->position_.moveRight();
}

