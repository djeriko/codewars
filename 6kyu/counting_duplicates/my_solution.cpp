#include <iostream>
#include <string>
#include <map>

using namespace std;

size_t duplicateCount(const string in)
{
  int result = 0;
  map<char, int> counter = {};
  for (auto c : in)
  {
    if (c >= 'A' && c <= 'Z')
    {
      c = c - 'A' + 'a';
    }

    map<char, int>::iterator it;
    it = counter.find(c);
    if (it->first == c)
    {
      it->second++;
    }
    else
    {
      counter.insert(pair<char, int>(c, 1));
    }
  }

  auto iter = counter.begin();
  while (iter != counter.end())
  {
    if (iter->second > 1)
    {
      result++;
    }
    iter++;
  }
  return result;
}

int main()
{
  cout << duplicateCount("Indivisibility");
  return 0;
}