A simple 2D game where the player controls a character moving around a map. The goal is to avoid enemies and shoot them with projectiles. The game includes enemy health points, collision detection, and a graphical user interface. Developed using the Qt library.

## Features

### Game Mechanics

- Player movement in four directions
- Projectile shooting system
- Random enemy spawning
- Collision detection between objects
- Enemy health points system

### User Interface

- Graphical interface using Qt
- Keyboard controls
- Real-time game state visualization

## Building and Running

### Building the Project

```bash
mkdir build
cd build
cmake ..
make
```

### Running the Game

```bash
make run
```

### Running Tests

```bash
cd unit_tests
mkdir build
cd build
cmake ..
make
./runTests
```
