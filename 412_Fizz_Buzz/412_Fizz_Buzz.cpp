#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
  std::vector<std::string> fizzBuzz(int n)
  {
    std::vector<std::string> fizzBuzzContainer;
    for (size_t i = 1; i <= n; i++)
    {
      if ((i % 3 == 0) && (i % 5 == 0))
      {
        fizzBuzzContainer.push_back("FizzBuzz");
      }
      else if (i % 3 == 0)
      {
        fizzBuzzContainer.push_back("Fizz");
      }
      else if (i % 5 == 0)
      {
        fizzBuzzContainer.push_back("Buzz");
      }
      else
      {
        fizzBuzzContainer.push_back(std::to_string(i));
      }
    }
    return fizzBuzzContainer;
  }
};

int main()
{
  Solution obj;
  std::vector<std::string> fizzBuzzOutput = obj.fizzBuzz(15);
  for (size_t i = 0; i < fizzBuzzOutput.size(); i++)
  {
    std::cout << fizzBuzzOutput.at(i) << " ";
  }
}