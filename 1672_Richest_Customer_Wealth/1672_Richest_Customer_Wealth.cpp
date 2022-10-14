#include <iostream>
#include <vector>

class Solution
{
public:
  int maximumWealth(std::vector<std::vector<int>> &accounts)
  {
    int max = -1;
    int tmp = 0;

    for (size_t i = 0; i < accounts.size(); i++)
    {
      for (size_t j = 0; j < accounts.at(i).size(); j++)
      {
        tmp = tmp + accounts.at(i).at(j);
      }
      if (max < tmp)
        max = tmp;
      tmp = 0;
    }
    return max;
  }
};

int main()
{
  Solution obj;
  std::vector<std::vector<int>> accounts{{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
  int richest = obj.maximumWealth(accounts);

  std::cout << richest << std::endl;

  return 0;
}