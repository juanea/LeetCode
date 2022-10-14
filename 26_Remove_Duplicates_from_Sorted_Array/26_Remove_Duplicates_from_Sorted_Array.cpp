#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
  int removeDuplicates(std::vector<int> &nums)
  {
    int tmp = -999;
    int repeatedNumbers = 0;

    for (size_t i = 0; i < nums.size(); i++)
    {
      if (tmp == nums.at(i))
      {
        repeatedNumbers++;
        tmp = nums.at(i);
        nums.at(i) = 999;
      }
      else
      {
        tmp = nums.at(i);
      }
    }
    std::sort(nums.begin(), nums.end());
    return nums.size() - repeatedNumbers;
  }
};

int main()
{
  Solution obj;
  std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int expectedOutput = obj.removeDuplicates(nums);
  std::cout << expectedOutput;
}