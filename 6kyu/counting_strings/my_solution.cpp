#include <string>
#include <iostream>

using namespace std;

int solve(const std::string &s)
{

  int sum = 0;
  int maxSum = 0;
  for (auto c : s)
  {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
      sum = 0;
    }
    else
    {
      sum = sum + c - 'a' + 1;
    }

    if (sum > maxSum)
    {
      maxSum = sum;
    }
  }
  return maxSum;
}

int main()
{
  int test = solve("zodiac");
  cout << test << endl;
  return 0;
}