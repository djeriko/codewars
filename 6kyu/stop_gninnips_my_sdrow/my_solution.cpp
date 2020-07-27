#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string spinWord(const string str)
{
  string result = "";
  string word = "";
  for (auto c : str)
  {
    if (c == ' ')
    {
      result += word + ' ';
      word = "";
      continue;
    }

    if (word.size() > 4)
    {
      reverse(word.begin(), word.end());
    }

    word += c;

    if (word.size() > 4)
    {
      reverse(word.begin(), word.end());
    }
  }
  result += word;
  return result;
}

int main()
{
  string s = "This is another test";
  cout << s << endl;
  string result = spinWord(s);
  cout << result << endl;
  return 0;
}