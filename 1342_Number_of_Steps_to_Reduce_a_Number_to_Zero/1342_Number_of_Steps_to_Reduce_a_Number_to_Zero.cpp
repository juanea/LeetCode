#include <iostream>

class Solution
{
public:
  int numberOfSteps(int num)
  {
    int ans = 0;
    while (num != 0)
    {
      if (num % 2 == 0)
        num = num / 2;
      else
        num--;
      ans++;
    }
    return ans;
  }
};

int main()
{
  Solution obj;
  int output = obj.numberOfSteps(14);
  std::cout << output << std::endl;
}