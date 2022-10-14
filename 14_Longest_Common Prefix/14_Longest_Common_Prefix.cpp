#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string longestCommonPrefix(std::vector<std::string> &strs)
{
  std::sort(strs.begin(), strs.end());
  std::string prefix = "";
  for (size_t i = 0; i < strs.at(0).size(); i++)
  {
    for (size_t j = 1; j < strs.size(); j++)
    {
      if (strs.at(j).at(i) != strs.at(0).at(i))
        return prefix;
    }
    prefix = prefix + strs.at(0).at(i);
  }
  return prefix;
}

int main()
{
  std::vector<std::string> words{"flower", "flow", "flight"};
  std::string result = longestCommonPrefix(words);
  std::cout << result << std::endl;
  words.clear();
  result.clear();
  words = {"dog", "racecar", "car"};
  result = longestCommonPrefix(words);
  std::cout << result << std::endl;
  words.clear();
  result.clear();
  words = {"colorado", "color", "cold"};
  result = longestCommonPrefix(words);
  std::cout << result << std::endl;
  words.clear();
  result.clear();
  words = {"a", "b", "c"};
  result = longestCommonPrefix(words);
  std::cout << result << std::endl;
  words.clear();
  result.clear();
  words = {"spot", "spotty", "spotted"};
  result = longestCommonPrefix(words);
  words.clear();
  result.clear();
  words = {"ab", "a"};
  result = longestCommonPrefix(words);
  std::cout << result << std::endl;
  return 0;
}