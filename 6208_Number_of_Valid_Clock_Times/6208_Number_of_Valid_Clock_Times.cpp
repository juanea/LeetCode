#include <iostream>
#include <string>

class Solution
{
public:
  int countTime(std::string time)
  {
    int answer = 1;
    if (time.at(0) == '?' && time.at(1) == '?')
    {
      answer *= 24;
    }
    else
    {
      if (time.at(0) == '?')
      {
        if (time.at(1) < '4')
        {
          answer *= 3;
        }
        else
        {
          answer *= 2;
        }
      }
      if (time.at(1) == '?')
      {
        if (time.at(0) == '2')
        {
          answer *= 4;
        }
        else
        {
          answer *= 10;
        }
      }
    }
    if (time.at(3) == '?')
    {
      answer *= 6;
    }
    if (time.at(4) == '?')
    {
      answer *= 10;
    }
    return answer;
  }
};

int main()
{
  Solution obj;
  // std::string time_ = {"?2:16"};
  int result_ = obj.countTime("?2:16");
  std::cout << result_ << std::endl;
  return 0;
}