#include <vector>
#include <iostream>

using namespace std;

bool validSolution(unsigned int board[9][9]){
  /* Write your solution here */
    std::vector<int> s{0,0,0};
    for (int i = 0; i < 9; ++i) {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < 9; ++j) {
            sum1 += board[i][j];
            sum2 += board[j][i];
            s[j/3] += board[i][j];
        }
        if (sum1 != 45) return false;
        if (sum2 != 45) return false;
        if ((i+1) % 3 == 0) {
            if (s != std::vector<int>{45,45,45})
                return false;
            s = {0,0,0};
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
