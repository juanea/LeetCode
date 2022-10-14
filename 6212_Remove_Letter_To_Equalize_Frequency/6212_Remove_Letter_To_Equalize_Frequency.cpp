#include <iostream>
#include <set>

class Solution
{
public:
  bool isBalanced(std::string wordMinuesOne)
  {
    int englishLetters[26] = {0};
    for (size_t i = 0; i < wordMinuesOne.size(); i++)
    {
      englishLetters[wordMinuesOne.at(i) - 'a'] += 1;
    }
    std::set<int> letterFreq;
    for (size_t j = 0; j < sizeof(englishLetters) / sizeof(englishLetters[0]); j++)
    {
      if (englishLetters[j] != 0)
        letterFreq.insert(englishLetters[j]);
    }
    return letterFreq.size() == 1;
  }
  bool equalFrequency(std::string word)
  {
    for (size_t i = 0; i < word.size(); i++)
    {
      std::string wordCopy = word;
      wordCopy.erase(i, 1);
      if (isBalanced(wordCopy))
        return true;
    }
    return false;
  }
};

int main()
{
  Solution obj;
  bool result = obj.equalFrequency("aaabbbcccc");
  std::cout << std::boolalpha << result << std::endl;
}