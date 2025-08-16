# Gra 2D - System Obiektów i Interakcji

Prosta gra 2D, w której gracz steruje postacią poruszającą się po planszy. Celem jest unikanie wrogów i strzelanie do nich pociskami. Gra zawiera system punktów życia wrogów, wykrywanie kolizji oraz graficzny interfejs użytkownika. Stworzona przy użyciu biblioteki Qt.

## Funkcjonalności

### Mechanika Gry

- Ruch gracza w czterech kierunkach
- System strzelania pociskami
- Generowanie wrogów w losowych pozycjach
- Wykrywanie kolizji między obiektami
- System punktów życia wrogów

### Interfejs Użytkownika

- Graficzny interfejs oparty na Qt
- Sterowanie klawiaturą
- Wizualizacja stanu gry w czasie rzeczywistym

## Kompilacja i Uruchomienie

### Budowanie Projektu

```bash
mkdir build
cd build
cmake ..
make
```

### Uruchomienie Gry

```bash
make run
```

### Uruchomienie Testów

```bash
cd unit_tests
mkdir build
cd build
cmake ..
make
./runTests
```
