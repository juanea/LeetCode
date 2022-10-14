#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
  bool canConstruct(std::string ransomNote, std::string magazine)
  {
    std::unordered_map<char, int> constructedMap;
    for (size_t i = 0; i < magazine.size(); i++)
    {
      constructedMap[magazine.at(i)] += 1;
    }
    for (size_t i = 0; i < ransomNote.size(); i++)
    {
      constructedMap[ransomNote.at(i)] -= 1;
    }
    for (auto &j : constructedMap)
    {
      if (j.second < 0)
      {
        return false;
      }
    }
    return true;
  }
};

int main()
{
  Solution obj;

  std::string ransomNote_ = "a", magazine_ = "b";

  bool result = obj.canConstruct(ransomNote_, magazine_);

  std::cout << std::boolalpha << result;
}