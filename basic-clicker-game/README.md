# Button Clicker

My first game built in C++ using **raylib**. This project focuses on learning the basics of C++ structure, 2D rendering, mouse input handling, and game state management.

## Features

* **Title & End Screens:** Includes a start menu (**PLAY** / **QUIT**) and a win screen (**PLAY AGAIN** / **QUIT**) that resets game state cleanly.
* **Click Counter:** Tracks total clicks and current clicks-per-click using 64-bit `long long` integers.
* **Three Upgrade Tiers:**
  * `+1 Click / Click` (cost scales linearly by `+5`)
  * `+100 Click / Click` (cost scales linearly by `+500`)
  * `x2 Click / Click` (cost scales exponentially by `1.9x`)
* **Win Condition:** Reaching **1,000,000,000** clicks completes the run.

## Controls

* **Left Mouse Button:** Click the button, purchase upgrades, and select menu options.

## How to Build and Run

Make sure **raylib** is installed on your system and that `Red_Buttons_Pixel.png` stays in the same directory as the compiled binary.

### Linux / WSL (Ubuntu)

```bash
cd basic-clicker-game
g++ main.cpp -o main -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./main
```

### Windows (MinGW / g++)

```bash
cd basic-clicker-game
g++ main.cpp -o main.exe -lraylib -lopengl32 -lgdi32 -lwinmm
main.exe
```
