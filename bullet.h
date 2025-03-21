#ifndef BULLET_H
#define BULLET_H

#include "object.h"
#include "direction.h"


/**
 * Proszę o utworzenie klasy `Bullet`, która będzie dziedziczyć po klasie `Object`, następnie proszę zakomentować `UNIMPLEMENTED_bulletIsObject`
 * - Klasa ta powinna mieć mieć składową `direction_`, a także operujący na niej getter (`direction()`) i setter (`setDirection`)
 * - Klasa powinna mieć dwu-argumentowy konstruktor przyjmujący kierunek i pozycje początkową
 * - Po zaimplementowania tego proszę zakomentować `UNIMPLEMENTED_bulletHasDirectionAndPosition`
 * - Klasa powinna zawierać statyczny atrybut odpowiadający prędkości o wartości `2`, oraz getter `speed()`
 */

//#define UNIMPLEMENTED_bulletIsObject
//#define UNIMPLEMENTED_bulletHasDirectionAndPosition


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
