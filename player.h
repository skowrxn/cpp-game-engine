#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "direction.h"

/**
 * Proszę o utworzenie klasy `Player`, która będzie dziedziczyć po klasie `Object`, następnie proszę zakomentować `UNIMPLEMENTED_playerIsObject`
 * - Klasa ta powinna mieć mieć składową `direction_`, a także operujący na niej getter i setter. Domyślna wartość to `Direction::RIGHT`
 *    - po zdefiniowaniu proszę usunąć `UNIMPLEMENTED_playerHasDirection`
 * - Klasa powinna mieć składową oznaczającą czy gracz żyje, oraz getter i setter: `isAlive()`, `setisAlive()`
 *    - po zdefiniowaniu proszę usunąć `UNIMPLEMENTED_playerCanDie`
 */

#define UNIMPLEMENTED_playerIsObject
#define UNIMPLEMENTED_playerHasDirection
#define UNIMPLEMENTED_playerCanDie

class Player : public Object
{
public:
    // TODO: ...
};

#endif // PLAYER_H
