// https : // leetcode.com/problems/add-binary/submissions/
#include <iostream>
#include <string>

std::string
reverseString(std::string *stringToReverse)
{
  std::string reverse;
  for (size_t i = 0; i < stringToReverse->size(); i++)
  {
    reverse.push_back(stringToReverse->at(stringToReverse->size() - i - 1));
  }
  return reverse;
}

std::string sumTwoBinaryStrings(std::string *stringOne, std::string *stringTwo)
{
  std::string temp;
  std::string result;
  int stringNumberOne = 0;
  int stringNumberTwo = 0;
  int carryOver = 0;
  int sum = 0;
  int longerString = 0;
  int shorterString = 0;
  char sumForString;

  for (int i = 0; i < stringOne->size(); i++)
  {
    if (stringOne->at(stringOne->size() - i - 1) == '1')
      stringNumberOne = 1;
    else
      stringNumberOne = 0;

    if (stringTwo->at(stringTwo->size() - i - 1) == '1')
      stringNumberTwo = 1;
    else
      stringNumberTwo = 0;

    sum = stringNumberOne + stringNumberTwo + carryOver;
    carryOver = 0;
    if (sum == 0)
    {
      sum = 0;
      sumForString = '0';
      carryOver = 0;
    }
    if (sum == 1)
    {
      sum = 0;
      sumForString = '1';
      carryOver = 0;
    }
    else if (sum == 2)
    {
      sum = 0;
      sumForString = '0';
      carryOver = 1;
    }
    else if (sum == 3)
    {
      sum = 1;
      sumForString = '1';
      carryOver = 1;
    }
    temp.push_back(sumForString);
  }
  if (carryOver == 1)
  {
    sumForString = '1';
    temp.push_back(sumForString);
  }
  return reverseString(&temp);
}

void addPaddingString(std::string *stringWithPadding, int padding)
{
  for (size_t i = 0; i < padding; i++)
  {
    *stringWithPadding = "0" + *stringWithPadding;
  }
}

int main()
{
  std::string binaryOne{"1010"};
  std::string binaryTwo{"1011"};

  if (binaryOne.size() > binaryTwo.size())
    addPaddingString(&binaryTwo, binaryOne.size() - binaryTwo.size());
  else if (binaryOne.size() < binaryTwo.size())
    addPaddingString(&binaryOne, binaryTwo.size() - binaryOne.size());

  std::cout << binaryOne << "  " << binaryTwo << std::endl;

  std::string binarySum = sumTwoBinaryStrings(&binaryOne, &binaryTwo);

  std::cout << binarySum << std::endl;

  return 0;
}
