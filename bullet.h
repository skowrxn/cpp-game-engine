#ifndef BULLET_H
#define BULLET_H

#include "object.h"
#include "direction.h"


/**
 * Proszę o utworzenie klasy `Bullet`, która będzie dziedziczyć po klasie `Object`, następnie proszę zakomentować `UNIMPLEMENTED_bulletIsObject`
 * - Klasa ta powinna mieć mieć składową `direction_`, a także operujący na niej getter i setter
 * - Klasa powinna mieć konstruktor przyjmujący kierunek i pozycje początkową
 * - Po zaimplementowania tego proszę zakomentować `UNIMPLEMENTED_bulletHasDirectionAndPosition`
 * - Klasa powinna zawierać statyczny atrybut odpowiadający prędkości o wartości `2`, oraz getter `speed()`
 */

#define UNIMPLEMENTED_bulletIsObject
#define UNIMPLEMENTED_bulletHasDirectionAndPosition


class Bullet : public Object
{
    // TODO:...
};

#endif // BULLET_H
