#include <iostream>
#include <algorithm>
#include <string>

class Solution
{
public:
  bool isAnagram(std::string s, std::string t)
  {
    int count = 0;
    if (s.length() != t.length())
      return false;
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    for (size_t i = 0; i < s.length(); i++)
    {
      if (s.at(i) != t.at(i))
        return false;
    }
    return true;
  }
};

int main()
{
  Solution obj;
  std::string strS{"rat"};
  std::string strT{"car"};

  bool result = obj.isAnagram(strS, strT);

  std::cout << std::boolalpha << result << std::endl;
}