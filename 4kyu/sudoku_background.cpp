#include <stdlib.h>
#include <iostream>

using namespace std;

// TODO : SOLVE TASK

bool usedInRow(unsigned int board[9][9], int row, int number)
{
  for (size_t col = 0; col < 9; col++)
  {
    if (board[col][row] == number)
    {
      return true;
    }
  }
  cout << "Error in row" << endl;
  return false;
}

bool usedInCol(unsigned int board[9][9], int col, int number)
{
  for (size_t row = 0; row < 9; row++)
  {
    if (board[col][row] == number)
    {
      return true;
    }
  }
  cout << "Error in col" << endl;
  return false;
}

bool usedInBox(unsigned int board[9][9], int boxStartRow, int boxStartCol, int number)
{
  for (size_t row = 0; row < 3; row++)
  {
    for (size_t col = 0; col < 3; col++)
    {
      if (board[row + boxStartRow][col + boxStartCol] == number)
      {
        return true;
      }
    }
  }
    cout << "Error in box" << endl;
    return false;
}

bool validSolution(unsigned int board[9][9])
{

  for (size_t number = 1; number <= 9; number++)
  {
    for (size_t row = 0; row < 9; row++)
      for (size_t col = 0; col < 9; col++)
      {
        {
          if (!usedInRow(board, row, number) || !usedInCol(board, row, number) || !usedInBox(board, row - row % 3, col - col % 3, number))
          {
            return false;
          }
        }
      }
  }
  return true;
}

int main()
{
  unsigned int example1[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                                 {6, 7, 2, 1, 9, 5, 3, 4, 8},
                                 {1, 9, 8, 3, 4, 2, 5, 6, 7},
                                 {8, 5, 9, 7, 6, 1, 4, 2, 3},
                                 {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                 {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                 {9, 6, 1, 5, 3, 7, 2, 8, 4},
                                 {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                 {3, 4, 5, 2, 8, 6, 1, 7, 9}};

  unsigned int example2[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                                 {6, 7, 2, 1, 9, 0, 3, 4, 8},
                                 {1, 0, 0, 3, 4, 2, 5, 6, 0},
                                 {8, 5, 9, 7, 6, 1, 0, 2, 0},
                                 {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                 {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                 {9, 0, 1, 5, 3, 7, 2, 1, 4},
                                 {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                 {3, 0, 0, 4, 8, 1, 1, 7, 9}};

  cout << validSolution(example1) << endl;
  cout << validSolution(example2) << endl;
  return 0;
}
