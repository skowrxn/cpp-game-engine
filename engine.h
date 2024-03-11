#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <memory> // std::shared_ptr && std::unique_ptr
#include "direction.h"
#include "player.h"
#include "stage.h"

struct Position;
class Bullet;
class Enemy;


Position generateNewEnemyPosition(int width, int height);

/** Proszę o zaimplementowanie klasy `Engine`, która będzie zarządzać obiektami, oraz będzie interfejsem do komunikacji z GUI.
 *  Szczegółowy opis poszczególnych metod znajduje się nad metodami.
 *  Nie są napisane testy dla całej klasy, więc możliwe jest przejście wszystkich testów, ale gra nie będzie działać.
 *  Można otrzymać punkty z aktywności za te zajęcia za uruchomienie gry i pokazanie mi (o ile nie ma ktoś już maksa z aktywności)
 */

#define UNIMPLEMENTED_engineConstructedWithWidthAndHeight
#define UNIMPLEMENTED_engineHasGettersToGetInformationAboutPlayer
#define UNIMPLEMENTED_engineCanMovePlayer
#define UNIMPLEMENTED_engineHandlePlayerShooting
#define UNIMPLEMENTED_engineHandlesEnemies

class Engine
{
public:
    /// Konstruktor, który dokona odpowiednich inicjalizacji
    Engine(std::size_t stageWidth, std::size_t stageHeight);

    /// Destruktor (jeśli trzeba)
    ~Engine();

    /// metody zwracające informacje o rozmiarze planszy
    std::size_t stageWidthCells() const;
    std::size_t stageHeightCells() const;

    /// zakomentowac makro: UNIMPLEMENTED_engineConstructedWithWidthAndHeight

    /// metody zwracające informacje na temat gracza
    Position playerPosition() const; /// domyslnie srodek planszy
    Direction playerDirection() const; /// domyślnie Direction::RIGHT
    bool isPlayerAlive() const;

    /// zakomentowac makro: UNIMPLEMENTED_engineHasGettersToGetInformationAboutPlayer

    /// metody obsługiwane z klawiatury
    void playerShoots();
    void movePlayerUp();
    void movePlayerDown();
    void movePlayerLeft();
    void movePlayerRight();

    /// zakomentowac makro: UNIMPLEMENTED_engineCanMovePlayer

    /// metody zwracające informacje na temat obiektów w grze
    const std::vector<Bullet>& bullets() const
    {
        return bullets_;
    }

    /// zakomentowac makro: UNIMPLEMENTED_engineHandlePlayerShooting

    /// metoda wywoływania kilka razy na sekundę, która ma za zadanie zaktualizowanie obiektów
    void update();

    const auto& enemies() const
    {
        return enemies_;
    }

protected:
    /// metoda, która doda określoną liczbę wrogów w miejscach zwróconych przez generator:
    void randEnemies(Position (*positionGenerator)(int, int)=generateNewEnemyPosition);
    /// metoda, która wpierw usunie zabitych wrogów, a następnie wykona ruch
    void updateEnemies();

    /// zakomentuj makro: UNIMPLEMENTED_engineHandlesEnemies

    /// metoda, która powinna zaktualizować pociski, czyli przesunąć je,
    /// obsłużyć trafienie wroga lub wyjście poza scenę
    void updateBullets();

private:
    // TODO: (Mozesz zaimplementowac dowolne metody pomocnicze)

private:
    Player player_;
    Stage stage_;
    std::vector<Bullet> bullets_;

    constexpr static std::size_t maxEnemies_ = 3;
    std::vector<std::shared_ptr<Enemy>> enemies_;
};

#endif // ENGINE_H
