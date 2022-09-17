#include <iostream>
#include <string>

bool isUpperCase(char *character)
{
  if (*character >= 'A' && *character <= 'Z')
    return true;
  else
    return false;
}

bool areAllCharactersUpperOrLower(std::string *wordCheckCharacters, bool allLettersUpperCase)
{
  for (size_t i = 1; i < wordCheckCharacters->size() - 1; i++)
  {
    if (isUpperCase(&wordCheckCharacters->at(i)) == allLettersUpperCase)
      continue;
    else
      return false;
  }
  return true;
}

bool isCapitalizationCorrectly(std::string *word)
{
  bool isCorrect = true;
  if (isUpperCase(&word->at(0)) == true && isUpperCase(&word->at(word->size() - 1)) == true)
  {
    // All should be capital
    return areAllCharactersUpperOrLower(word, true);
  }
  else if (isUpperCase(&word->at(0)) == false && isUpperCase(&word->at(word->size() - 1)) == false)
  {
    // First is capital rest lower case
    return areAllCharactersUpperOrLower(word, false);
  }
  else if (isUpperCase(&word->at(0)) == true && isUpperCase(&word->at(word->size() - 1)) == false)
  {
    // All lower case
    return areAllCharactersUpperOrLower(word, false);
  }
  else
  {
    return false;
  }
}

int main()
{
  std::string capitalizationCorrectly = "USA";
  std::cout << std::boolalpha << isCapitalizationCorrectly(&capitalizationCorrectly) << std::endl;
  capitalizationCorrectly.clear();
  capitalizationCorrectly = "Calvin";
  std::cout << std::boolalpha << isCapitalizationCorrectly(&capitalizationCorrectly) << std::endl;
  capitalizationCorrectly.clear();
  capitalizationCorrectly = "compUter";
  std::cout << std::boolalpha << isCapitalizationCorrectly(&capitalizationCorrectly) << std::endl;
  capitalizationCorrectly.clear();
  capitalizationCorrectly = "coding";
  std::cout << std::boolalpha << isCapitalizationCorrectly(&capitalizationCorrectly) << std::endl;
  return 0;
}