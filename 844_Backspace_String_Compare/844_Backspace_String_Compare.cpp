#include <iostream>
#include <stack>
#include <string>

class Solution
{
public:
  bool backspaceCompare(std::string s, std::string t)
  {
    std::stack<char> strS;
    std::stack<char> strT;
    for (size_t i = 0; i < s.size(); i++)
    {
      if (s.at(i) == '#' && !strS.empty())
        strS.pop();
      else if (s.at(i) != '#')
        strS.push(s.at(i));
    }
    for (size_t i = 0; i < t.size(); i++)
    {
      if (t.at(i) == '#' && !strT.empty())
        strT.pop();
      else if (t.at(i) != '#')
        strT.push(t.at(i));
    }
    while (!strS.empty() || !strT.empty())
    {
      if (strS.empty())
      {
        return false;
      }
      else if (strT.empty())
      {
        return false;
      }
      else if (strS.top() == strT.top())
      {
        strS.pop();
        strT.pop();
      }
      else
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
  std::string s_ = "y#fo##f";
  std::string t_ = "y#f#o##f";
  bool result_ = obj.backspaceCompare(s_, t_);
  std::cout << std::boolalpha << result_ << std::endl;
}