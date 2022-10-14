#include <iostream>
#include <stack>
#include <string>

class Solution
{
public:
  bool isValid(std::string s)
  {
    std::stack<char> validParentheses;
    for (size_t i = 0; i < s.size(); i++)
    {
      if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{')
      {
        validParentheses.push(s.at(i));
      }
      else if (s.at(i) == ')' && !validParentheses.empty() && validParentheses.top() == '(')
      {
        validParentheses.pop();
      }
      else if (s.at(i) == ']' && !validParentheses.empty() && validParentheses.top() == '[')
      {
        validParentheses.pop();
      }
      else if (s.at(i) == '}' && !validParentheses.empty() && validParentheses.top() == '{')
      {
        validParentheses.pop();
      }
      else
        return false;
    }
    return validParentheses.empty();
  }
};

int main()
{
  Solution obj;
  bool result_ = obj.isValid("()[]{}");
  std::cout << std::boolalpha << result_ << std::endl;
}