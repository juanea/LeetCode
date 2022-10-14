#include <iostream>
#include <climits>

class Solution
{
public:
  int reverse(int x)
  {
    int reverseNumber = 0;
    bool flagIsItNegative = false;
    int lastDigit = 0;

    if ((long long)x > INT_MAX || (long long)x < INT_MAX * -1)
      return 0;
    if (x < 0)
    {
      x = x * -1;
      flagIsItNegative = true;
    }
    while (x > 0)
    {
      lastDigit = x % 10;
      x = x / 10;
      if ((long long)reverseNumber * 10 + lastDigit > INT_MAX)
        return 0;
      reverseNumber = reverseNumber * 10 + lastDigit;
    }
    if (flagIsItNegative)
      return reverseNumber * -1;
    return reverseNumber;
  }
};

int main()
{
  Solution sol;
  int reverse = sol.reverse(123);
  std::cout << reverse << std::endl;
}