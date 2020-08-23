#include <vector>
char add_letters(std::vector<char> letters)
{
  constexpr const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  int index = 25;

  for (const char c : letters)
  {
    index = (index + (c - 'a' + 1)) % 26;
  }
  return alphabet[index];
}