# CMakeLists.txt
# Configures the Tic-Tac-Toe project build. Defines the C++ standard,
# include paths, and source files required to build the executable.

cmake_minimum_required(VERSION 3.10)

project(TicTacToe
    VERSION 1.0
    DESCRIPTION "Simple Tic-Tac-Toe game in C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include header files
include_directories(include)

# Source files
add_executable(tictactoe
    src/main.cpp
    src/utils.cpp
)

CMD ["./build/tictactoe"]
