/*
    13_Roman_to_Integer.cpp
    Author: Juan Echavarria (juanea@gmail.com)
    https://leetcode.com/problems/roman-to-integer/
    Program to convert a roman numeral into an integer.
    Note:
    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.
*/

#include <iostream>
#include <string>

class Solution
{
public:
  int roman_to_int(std::string roman_string)
  {
    int look_up_table[10][3] = {0};

    look_up_table[0][0] = 1;
    look_up_table[1][0] = 5;
    look_up_table[2][0] = 10;
    look_up_table[3][0] = 50;
    look_up_table[4][0] = 100;
    look_up_table[5][0] = 500;
    look_up_table[6][0] = 1000;

    look_up_table[0][1] = 'I';
    look_up_table[1][1] = 'V';
    look_up_table[2][1] = 'X';
    look_up_table[3][1] = 'L';
    look_up_table[4][1] = 'C';
    look_up_table[5][1] = 'D';
    look_up_table[6][1] = 'M';

    int decimal_number = 0;

    for (int i = roman_string.length() - 1; i >= 0; i--)
    {
      for (size_t j = 0; j < sizeof(look_up_table); j++)
      {
        if (look_up_table[j][1] == roman_string[i])
        {
          if (roman_string[i] == 'I' && roman_string[i + 1] == 'V' ||
              roman_string[i] == 'I' && roman_string[i + 1] == 'X' ||
              roman_string[i] == 'X' && roman_string[i + 1] == 'L' ||
              roman_string[i] == 'X' && roman_string[i + 1] == 'C' ||
              roman_string[i] == 'C' && roman_string[i + 1] == 'D' ||
              roman_string[i] == 'C' && roman_string[i + 1] == 'M')
          {
            decimal_number = decimal_number - look_up_table[j][0];
            break;
          }
          else
          {
            decimal_number = decimal_number + look_up_table[j][0];
            break;
          }
        }
      }
    }
    return decimal_number;
  }
};

int main(int argc, char const *argv[])
{
  std::string roman_number;
  std::cin >> roman_number;
  Solution obj;
  int int_result = obj.roman_to_int(roman_number);
  std::cout << int_result << std::endl;
  return 0;
}
