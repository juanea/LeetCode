#include <algorithm>
#include <iostream>
#include <string>
#include <stack>

class Solution
{
public:
  std::string removeDuplicates(std::string s)
  {
    std::stack<char> removeAdjancentDuplicates;
    removeAdjancentDuplicates.push(s.at(0));
    std::string res;
    for (size_t i = 1; i < s.size(); i++)
    {
      if(!removeAdjancentDuplicates.empty())
      {
        if (s.at(i) == removeAdjancentDuplicates.top())
          removeAdjancentDuplicates.pop(); 
        else
          removeAdjancentDuplicates.push(s.at(i));
      }
      else
        removeAdjancentDuplicates.push(s.at(i));
    }
    while (!removeAdjancentDuplicates.empty())
    {
      res+=removeAdjancentDuplicates.top();
      removeAdjancentDuplicates.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main()
{
  Solution obj;
  std::string result_;
  result_ = obj.removeDuplicates("abbaca");
  std::cout << result_ << std::endl;
  return 0;
}