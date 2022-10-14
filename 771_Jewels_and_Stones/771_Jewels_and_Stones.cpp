#include <iostream>
#include <string>

class Solution
{
public:
  int numJewelsInStones(std::string jewels, std::string stones)
  {
    int arr[1000][2] = {0};
    int tmp = 0;
    bool flag = false;
    for (size_t i = 0; i < stones.length(); i++)
    {
      arr[static_cast<int>(stones.at(i))][0] = arr[static_cast<int>(stones.at(i))][0] + 1;
    }
    for (size_t i = 0; i < jewels.length(); i++)
    {
      arr[static_cast<int>(jewels.at(i))][1] = 1;
    }
    for (size_t i = 0; i < 1000; i++)
    {
      if (arr[i][1] == 1)
      {
        tmp = tmp + arr[i][0];
      }
    }
    return tmp;
  }
};

int main()
{
  Solution obj;
  std::string myJewels{"ebd"};
  std::string myStones{"bbb"};
  int result = obj.numJewelsInStones(myJewels, myStones);
  std::cout << result << std::endl;
}