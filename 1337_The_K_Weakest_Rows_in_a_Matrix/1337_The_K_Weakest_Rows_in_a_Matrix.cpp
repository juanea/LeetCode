#include <algorithm>
#include <utility>
#include <vector>

class Solution
{
public:
  std::vector<int> kWeakestRows(std::vector<std::vector<int>> &mat, int k)
  {
    std::vector<std::pair<int, int>> freq;
    for (size_t i = 0; i < mat.size(); i++)
    {
      int temp = 0;
      for (size_t j = 0; j < mat.at(i).size(); j++)
      {
        temp += mat.at(i).at(j);
      }
      freq.push_back(std::make_pair(temp, i));
    }
    std::sort(freq.begin(), freq.end());
    std::vector<int> result;
    for (size_t i = 0; i < k; i++)
    {
      result.push_back(freq.at(i).second);
    }
    return result;
  }
};

int main()
{
  Solution obj;

  std::vector<std::vector<int>> mat_ = {{1, 1, 0, 0, 0},
                                        {1, 1, 1, 1, 0},
                                        {1, 0, 0, 0, 0},
                                        {1, 1, 0, 0, 0},
                                        {1, 1, 1, 1, 1}};

  std::vector<int> res = obj.kWeakestRows(mat_, 3);
  return 0;
}