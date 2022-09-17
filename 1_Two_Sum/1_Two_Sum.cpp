#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target)
  {
    std::vector<int> result;
    for (size_t i = 0; i < nums.size(); i++)
    {
      for (size_t j = 0; j < nums.size(); j++)
      {
        if (nums.at(i) + nums.at(j) == target && i != j)
        {
          result.push_back(i);
          result.push_back(j);
          return result;
        }
      }
    }
    return result;
  }
};

int main()
{
  Solution obj;
  std::vector<int> numbers{-1, -2, -3, -4, -5};
  std::vector<int> sumResult;
  sumResult = obj.twoSum(numbers, -8);

  for (size_t i = 0; i < sumResult.size(); i++)
  {
    std::cout << sumResult.at(i);
  }
  std::cout << std::endl;
}