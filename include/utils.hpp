// utils.hpp
// Declares utility functions for the Tic-Tac-Toe game, including board
// rendering, move validation, win checking, and player configuration.
// Also provides small inline helpers for row, column, and diagonal checks.

#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>

/**
 * @brief Prints the Tic-Tac-Toe board with row/column labels.
 *
 * @param board 3×3 game board containing '.', 'x', or 'o'.
 */
void ShowBoard(const std::vector<std::vector<char>>& board);

/**
 * @brief Checks whether the given player has three in a row.
 *
 * @param row Row index of the last move.
 * @param col Column index of the last move.
 * @param sign Player symbol ('x' or 'o').
 * @param board 3×3 game board.
 * @return true if the player has three in a row, false otherwise.
 */
bool CheckThreeInARow(int row, int col, char sign,
                      const std::vector<std::vector<char>>& board);

/**
 * @brief Attempts to place a sign in the given cell.
 *
 * @param row Row index.
 * @param col Column index.
 * @param sign Player symbol ('x' or 'o').
 * @param board Reference to the game board.
 * @return true if the move is valid and placed, false otherwise.
 */
bool CheckCell(int row, int col, char sign,
               std::vector<std::vector<char>>& board);

/**
 * @brief Reads a row and column from user input safely.
 *
 * @param row Output row index.
 * @param col Output column index.
 * @return true if valid numeric input was read, false otherwise.
 */
bool ReadMove(int& row, int& col);

/**
 * @brief Randomly selects which player starts.
 *
 * @return 'x' or 'o'.
 */
char PlayerConfig();


// ---------------------------------------------------------------------------
// Inline helper functions for CheckThreeInARow()
// ---------------------------------------------------------------------------

/**
 * @brief Checks if a row contains three identical signs.
 */
inline bool CheckRow(int row, char sign,
                     const std::vector<std::vector<char>>& b) {
  return b[row][0] == sign && b[row][1] == sign && b[row][2] == sign;
}

/**
 * @brief Checks if a column contains three identical signs.
 */
inline bool CheckCol(int col, char sign,
                     const std::vector<std::vector<char>>& b) {
  return b[0][col] == sign && b[1][col] == sign && b[2][col] == sign;
}

/**
 * @brief Checks the main diagonal.
 */
inline bool CheckMainDiag(char sign,
                          const std::vector<std::vector<char>>& b) {
  return b[0][0] == sign && b[1][1] == sign && b[2][2] == sign;
}

/**
 * @brief Checks the anti-diagonal.
 */
inline bool CheckAntiDiag(char sign,
                          const std::vector<std::vector<char>>& b) {
  return b[0][2] == sign && b[1][1] == sign && b[2][0] == sign;
}

#endif  // UTILS_HPP