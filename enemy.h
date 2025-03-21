#ifndef ENEMY_H
#define ENEMY_H

#include <chrono>
#include "object.h"

/**
 * Proszę o utworzenie klasy `Enemy`, która będzie dziedziczyć po klasie `Object`
 * - Klasa ta powinna mieć mieć składową odpowiadającą ilości punktów życia, oraz getter: `lifePercent()` (**W PROCENTACH!**)
 * - Klasa powinna mieć konstruktor przyjmujący aktualną pozycje oraz maksymalne życie z wartością domyślną (dwu-argumentowy, który można wywołać z jednym argumentem)
 * - Klasa powinna mieć metodę `isAlive()` która zwraca prawdę jeśli wróg ma życie powyżej zera
 * - Klasa powinna mieć metodę `decreaseLife()` przyjmującą jako argument liczbę obrażeń
 * - Po zaimplementowaniu powyższego proszę zakomentować makro `UNIMPLEMENTED_enemy`
 */

//#define UNIMPLEMENTED_enemy

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
