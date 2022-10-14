#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Solution
{
public:
  std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2)
  {
    s1 = s1 + ' ' + s2 + ' ';
    int point_front = 0;
    int point_back = 0;
    std::string word;
    std::unordered_map<std::string, int> sentences;
    std::vector<std::string> result;
    for (size_t i = 0; i < s1.length(); i++)
    {
      if (isspace(s1.at(i)))
      {
        point_back = i;
        word = s1.substr(point_front, (point_back - point_front));
        sentences[word] += 1;
        point_front = i + 1;
      }
    }
    for (auto &x : sentences)
    {
      if (x.second == 1)
      {
        result.push_back(x.first);
      }
    }
    return result;
  }
};

int main()
{
  Solution obj;

  std::string s1_ = "this apple is sweet";
  std::string s2_ = "this apple is sour";

  std::vector<std::string> uncommon_words;
  uncommon_words = obj.uncommonFromSentences(s1_, s2_);

  for (auto &j : uncommon_words)
  {
    std::cout << j << std::endl;
  }
}