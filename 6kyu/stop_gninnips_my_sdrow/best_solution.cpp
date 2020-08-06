#include <string>
#include <algorithm>
#include <sstream>
#include <iostream>
std::string spinWords(const std::string &str)
{
  std::stringstream ss(str);
  std::string result;
  std::string buff;
  while (ss >> buff)
  {
    if (buff.size() >= 5)
    {
      std::reverse(buff.begin(), buff.end());
    }
    result += buff + ' ';
  }
  result.pop_back();
  return result;
}

int main()
{
  std::string s = "This is another test";
  std::cout << s << std::endl;
  std::string result = spinWords(s);
  std::cout << result << std::endl;
  return 0;
}