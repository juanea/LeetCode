#include <iostream>
#include <string>

class Solution
{
public:
  bool validPalindrome(std::string s)
  {
    int i = 0;
    int j = s.size() - 1;
    for (int i = 0; i < j; i++)
    {
      if (s.at(i) != s.at(j))
      {
        return isItPalindrome(s, i + 1, j) || isItPalindrome(s, i, j - 1);
      }
      j--;
    }
    return true;
  }

  bool isItPalindrome(std::string str, int i, int j)
  {
    for (; i < j; i++)
    {
      if (str.at(i) != str.at(j))
      {
        return false;
      }
      j--;
    }
    return true;
  }
};

int main()
{
  Solution palindrome;
  std::string str{"abca"};
  bool isItPalindrome = palindrome.validPalindrome(str);
  std::cout << std::boolalpha << isItPalindrome << std::endl;
}