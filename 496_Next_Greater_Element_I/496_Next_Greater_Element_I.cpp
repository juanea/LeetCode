#include <iostream>
#include <vector>

class Solution
{
public:
  std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
  {
    std::vector<int> ans;
    bool found = false;
    for (size_t i = 0; i < nums1.size(); i++)
    {
      for (size_t j = 0; j < nums2.size(); j++)
      {
        if (nums1.at(i) == nums2.at(j))
        {
          if (j == nums2.size() - 1)
          {
            break;
          }
          for (size_t k = j; k < nums2.size(); k++)
          {
            if (nums2.at(j) < nums2.at(k))
            {
              ans.push_back(nums2.at(k));
              found = true;
              break;
            }
          }
        }
        else if (found)
        {
          break; 
        }
      }
      if(!found)
        ans.push_back(-1);
      found = false;
    }
    return ans;
  }
};
int main()
{
  Solution obj;
  std::vector<int> nums1_ = {1, 3, 5, 2, 4};
  std::vector<int> nums2_ = {6, 5, 4, 3, 2, 1, 7}; 
  std::vector<int> result_;
  result_ = obj.nextGreaterElement(nums1_, nums2_);
  for (size_t i = 0; i < result_.size(); i++)
  {
    std::cout << result_.at(i);
  }
  std::cout << std::endl;
  return 0;
}