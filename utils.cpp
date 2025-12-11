#include "utils.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::vector;

/**
 * @copydoc ShowBoard()
 */
void ShowBoard(const vector<vector<char>>& board) {
  cout << "   0 1 2\n";
  cout << "  -------\n";
  for (int row = 0; row < 3; ++row) {
    cout << row << "| ";
    for (int col = 0; col < 3; ++col) {
      cout << board[row][col] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}

/**
 * @copydoc CheckThreeInARow()
 */
bool CheckThreeInARow(int row, int col, char sign,
                      const vector<vector<char>>& b) {
  if (CheckRow(row, sign, b)) return true;
  if (CheckCol(col, sign, b)) return true;
  if (row == col && CheckMainDiag(sign, b)) return true;
  if (row + col == 2 && CheckAntiDiag(sign, b)) return true;
  return false;
}

/**
 * @copydoc CheckCell()
 */
bool CheckCell(int row, int col, char sign,
               vector<vector<char>>& board) {
  if (row < 0 || row > 2 || col < 0 || col > 2) {
    cout << "Invalid coordinates. Try again.\n";
    return false;
  }

  if (board[row][col] != '.') {
    cout << "Cell already occupied.\n";
    return false;
  }

  board[row][col] = sign;
  return true;
}

/**
 * @copydoc ReadMove()
 */
bool ReadMove(int& row, int& col) {
  if (!(cin >> row >> col)) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input. Enter two numbers.\n";
    return false;
  }
  return true;
}

/**
 * @copydoc PlayerConfig()
 */
char PlayerConfig() {
  return (std::rand() % 2 == 0) ? 'x' : 'o';
}