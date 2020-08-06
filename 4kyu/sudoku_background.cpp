#include <stdlib.h>
#include <iostream>

using namespace std;

// TODO : SOLVE TASK

bool validSolution(unsigned int board[9][9])
{
  for (size_t i = 0; i < 9; i++)
  {
    int rowSum = 0;
    bool n1 = false, n2 = false, n3 = false, n4 = false, n5 = false, n6 = false, n7 = false, n8 = false, n9 = false;

    for (size_t j = 0; j < 9; j++)
    {
      rowSum += board[i][j];
      if (board[i][j] == 0)
      {
        return false;
      }

      board[i][j] == 1 ? n1 = true : 0;
      board[i][j] == 2 ? n2 = true : 0;
      board[i][j] == 3 ? n3 = true : 0;
      board[i][j] == 4 ? n4 = true : 0;
      board[i][j] == 5 ? n5 = true : 0;
      board[i][j] == 6 ? n6 = true : 0;
      board[i][j] == 7 ? n7 = true : 0;
      board[i][j] == 8 ? n8 = true : 0;
      board[i][j] == 9 ? n9 = true : 0;
    }

    if (!n1 || !n2 || !n3 || !n4 || !n5 || !n6 || !n7 || !n8 || !n9)
      return false;

    if (rowSum != (9 + 8 + 7 + 6 + 5 + 4 + 3 + 2 + 1))
    {
      return false;
    }
  }

  for (size_t i = 0; i < 9; i++)
  {
    bool w1 = false, w2 = false, w3 = false, w4 = false, w5 = false, w6 = false, w7 = false, w8 = false, w9 = false;
    for (size_t j = 0; j < 9; j++)
    {
      board[j][i] = 1 ? w1 = true : 0;
      board[j][i] = 2 ? w2 = true : 0;
      board[j][i] = 3 ? w3 = true : 0;
      board[j][i] = 4 ? w4 = true : 0;
      board[j][i] = 5 ? w5 = true : 0;
      board[j][i] = 6 ? w6 = true : 0;
      board[j][i] = 7 ? w7 = true : 0;
      board[j][i] = 8 ? w8 = true : 0;
      board[j][i] = 9 ? w9 = true : 0;
    }

    if (!w1 || !w2 || !w3 || !w4 || !w5 || !w6 || !w7 || !w8 || !w9)
      return false;
  }

  for (size_t k = 0; k < 6; k += 3)
  {
    for (size_t g = 0; g < 6; g += 3)
    {
      int sumOfThree = 0;
      for (size_t i = 0; i < 3; i++)
      {
        for (size_t j = 0; j < 3; j++)
        {
          sumOfThree += board[i + k][j + g];
        }
      }
      if (sumOfThree != (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9))
        return false;
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
  return 0;
}
