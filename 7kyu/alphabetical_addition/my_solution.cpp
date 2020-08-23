#include <iostream>
#include <vector>

using namespace std;

char add_letters(vector<char> letters)
{
  if (letters.size() == 0)
    return 'z';
  int sum = 0;
  for (auto c : letters)
  {
    sum += c - 'a' + 1;
    cout << sum << endl;
    if (sum > 'z' - 'a' + 1)
    {
      sum -= 'z' - 'a' + 1;
      cout << "Overflow " << sum << endl;
      cout << "z - a " << 'z' - 'a' << endl;
    }
  }
  sum += 'a' - 1;
  return sum;
}

int main()
{
  vector<char> test = {'z'};
  char result = add_letters(test);
  cout << "This is result " << result << endl;
  return 0;
}