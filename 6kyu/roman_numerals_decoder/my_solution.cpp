#include <iostream>
#include <string>

using namespace std;

int counter(char c)
{
  int temp = 0;
  if (c == 'I')
  {
    temp = 1;
  }
  else if (c == 'V')
  {
    temp = 5;
  }
  else if (c == 'X')
  {
    temp = 10;
  }
  else if (c == 'L')
  {
    temp = 50;
  }
  else if (c == 'C')
  {
    temp = 100;
  }
  else if (c == 'D')
  {
    temp = 500;
  }
  else if (c == 'M')
  {
    temp = 1000;
  }
  return temp;
}

int solution(string roman)
{
  int result = 0;
  int length = (int)roman.size();

  for (int i = 0; i < length; i++)
  {
    int current = counter(roman[i]);
    int previous = counter(roman[i - 1]);
    int next = counter(roman[i + 1]);

    if (current > previous && i != 0)
    {
      continue;
    }
    else if (current >= next && (int)roman.size() != i + 1)
    {
      result += current;
    }
    else if (current < next)
    {
      result += next - current;
    }
    else if (length == i + 1 && current <= previous)
    {
      result += current;
    }
    else if (length == 1)
    {
      result = current;
    }
  }
  return result;
}

int main()
{
  cout << solution("MDCLXVI");
  return 0;
}