#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(string s)
{
  string pair = "";
  vector<string> result;
  for (int i = 0; i <= s.size(); i++)
  {
    if (i > 0 && i % 2 == 0)
    {
      result.push_back(pair);
      pair = "";
    }
    pair += s[i];
    if (i == s.size() && i % 2 != 0)
    {
      pair += "_";
      result.push_back(pair);
    }
  }
  return result;
}

int main()
{
  vector<string> answer = solution("abcdef112");
  for (auto i = answer.begin(); i != answer.end(); ++i)
    cout << *i << endl;
  cout << "check";
  return 0;
}