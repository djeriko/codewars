#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> nums = {{'M', 1000},
                       {'D', 500},
                       {'C', 100},
                       {'L', 50},
                       {'X', 10},
                       {'V', 5},
                       {'I', 1}};

int solution(string roman)
{
  int res = 0;
  int old = 0;

  for (auto c : roman)
  {
    int curr = nums[c];
    res += curr;

    if (curr > old)
    {
      res -= 2 * old;
    }

    old = curr;
  }
  return res;
}

int main()
{
  cout << solution("MDCLXVI");
  return 0;
}