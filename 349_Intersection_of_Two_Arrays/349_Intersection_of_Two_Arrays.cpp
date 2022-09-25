#include <iostream>
#include <unordered_set>
#include <vector>

class Solution
{
public:
  std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
  {
    std::unordered_set<int> hashSet;
    for (auto i : nums1)
    {
      hashSet.insert(i);
    }
    std::unordered_set<int> hashSetIntersection;
    for (auto i : nums2)
    {
      auto search = hashSet.find(i);
      if (search != hashSet.end())
      {
        hashSetIntersection.insert(i);
      }
    }
    std::vector<int> result;
    for (auto &j : hashSetIntersection)
    {
      result.push_back(j);
    }
    return result;
  }
};

int main()
{
  Solution obj;
  std::vector<int> nums1_{4, 9, 5};
  std::vector<int> nums2_{9, 4, 9, 8, 4};
  std::vector<int> sol = obj.intersection(nums1_, nums2_);
  for (auto i : sol)
    std::cout << sol.at(i);
  std::cout << std::endl;
}