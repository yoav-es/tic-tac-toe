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

# Create the executable
add_executable(tictactoe
    main.cpp
    utils.cpp
)

# Add warnings
if (MSVC)
    target_compile_options(tictactoe PRIVATE /W4)
else()
    target_compile_options(tictactoe PRIVATE -Wall -Wextra -Wpedantic)
endif()
