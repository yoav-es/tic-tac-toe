// main.cpp
// Contains the main game loop for Tic-Tac-Toe. Handles turn order,
// score tracking, repeated play, and interaction with the utility
// functions that manage board state and win detection.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "utils.hpp"

using std::cout;
using std::cin;
using std::vector;

/**
 * @brief Runs one full game of Tic-Tac-Toe.
 *
 * Handles turn-taking, move validation, win detection, and tie detection.
 *
 * @param player Starting player ('x' or 'o').
 * @param board 3×3 game board.
 * @return 'x' if X wins, 'o' if O wins, 't' if tie.
 */
char PlayGame(char player, vector<vector<char>>& board) {
  int row = 0;
  int col = 0;
  int move_count = 0;

  while (move_count < 9) {
    ShowBoard(board);

    cout << "Current player: " << player << "\n";
    cout << "Enter row and column (0-2 0-2): ";

    if (!ReadMove(row, col)) {
      continue;
    }

    if (CheckCell(row, col, player, board)) {
      ++move_count;

      if (CheckThreeInARow(row, col, player, board)) {
        cout << "\nPlayer " << (player == 'x' ? 1 : 2)
             << " (" << player << ") wins!\n\n";
        ShowBoard(board);
        return player;
      }

      player = (player == 'x') ? 'o' : 'x';
    }
  }

  cout << "It's a tie!\n";
  ShowBoard(board);
  return 't';
}

/**
 * @brief Entry point for the Tic-Tac-Toe program.
 *
 * Handles score tracking and play-again loop.
 */
int main() {
  std::srand(std::time(nullptr));

  int score_x = 0;
  int score_o = 0;

  cout << "Welcome to Tic-Tac-Toe!\n";

  while (true) {
    vector<vector<char>> board(3, vector<char>(3, '.'));

    char current = PlayerConfig();
    cout << "\nStarting player: " << current << "\n";

    char result = PlayGame(current, board);

    if (result == 'x') {
      ++score_x;
    } else if (result == 'o') {
      ++score_o;
    }

    cout << "Score: X=" << score_x << " | O=" << score_o << "\n";

    cout << "Play again? (y/n): ";
    char again;
    cin >> again;

    if (again != 'y' && again != 'Y') {
      cout << "Thanks for playing.\n";
      break;
    }
  }

  return 0;
}