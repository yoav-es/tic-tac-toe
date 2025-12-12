# Tic-Tac-Toe – C++ game

A simple command-line Tic-Tac-Toe game implemented in modern C++17.  
It supports repeated play, score tracking, and clear board rendering with colored output for players.

---

## Project structure – Tic-Tac-Toe

TicTacToe/
  src/
    main.cpp                  # Main game loop, turn order, score tracking
    utils.cpp                 # Utility functions: board display, input handling, win detection
  include/
    utils.hpp                 # Declarations and inline helpers for board checks
  CMakeLists.txt              # Build configuration with CMake
  Dockerfile                  # Containerization for building and running the game
  LICENSE                     # MIT License
  .github/workflows/
    build.yml                 # GitHub Actions workflow for cross-platform builds
    release.yml               # GitHub Actions workflow for tagged releases

---

## Features

- **Interactive gameplay:** Command-line interface with turn prompts.
- **Colored output:** X in red, O in blue for easy readability.
- **Input validation:** Safe parsing and rejection of invalid or occupied moves.
- **Win detection:** Rows, columns, main diagonal, and anti-diagonal checks.
- **Tie handling:** Declares a tie when the board is full.
- **Score tracking:** Accumulates wins across repeated rounds.
- **Starting player:** Randomized selection between X and O.

---
## Downloads

Grab the latest precompiled binaries here:

- [Windows](https://github.com/yoav-es/tic-tac-toe/releases/latest/download/tictactoe-windows.exe)
- [Linux](https://github.com/yoav-es/tic-tac-toe/releases/latest/download/tictactoe-linux)
- [macOS](https://github.com/yoav-es/tic-tac-toe/releases/latest/download/tictactoe-macos)

---

## Using g++
  Direct compilation without CMake:
  ```bash
  g++ src/main.cpp src/utils.cpp -I include -o tictactoe.exe
   ```
  ./tictactoe.exe

  ## Build and run

  ### Using CMake
  
  1. **Configure:**
  ```
    cmake -B build -S .
  ```
  2. **Build:**
  ```
    cmake --build build
  ```
  3. **Run:**
  ```
    ./build/tictactoe
  ```
  ### Using Docker
  1. **Build image:**
  ```
    docker build -t tictactoe .
  ```
  2. **Run container:**
  ```
    docker run -it tictactoe
  ```

---

## GitHub Actions

- **Build workflow (build.yml):** Compiles the project on Linux, Windows, and macOS with CMake and uploads platform-specific artifacts.
- **Release workflow (release.yml):** Triggers on version tags (v*) and publishes a GitHub Release with bundled artifacts.

---

## License

This project is licensed under the MIT License. See the LICENSE file for details.
