#include <iostream>
#include <string>
#include <map>
#include <climits>

class Solution
{
public:
  int firstUniqChar(std::string s)
  {
    std::map<char, int> hashMap;
    for (size_t i = 0; i < s.length(); i++)
    {
      char current = s.at(i);
      auto search = hashMap.find(current);
      if (search == hashMap.end())
      {
        hashMap.insert(std::pair<char, int>(current, i));
      }
      else
      {
        search->second = -1;
      }
    }
    int min = INT_MAX;
    for (auto pair : hashMap)
    {
      if (pair.second > -1 && pair.second < min)
      {
        min = pair.second;
      }
    }
    return min == INT_MAX ? -1 : min;
  }
};

int main()
{
  Solution obj;
  std::string str{"loveleetcode"};
  int solutionIndex = obj.firstUniqChar(str);
  std::cout << solutionIndex;
}