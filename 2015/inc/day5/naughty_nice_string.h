//
// Created by kieran McNamara on 16/12/2021.
//

#ifndef ADVENTOFCODE_2015_INC_DAY5_NAUGHTY_NICE_STRING_H_
#define ADVENTOFCODE_2015_INC_DAY5_NAUGHTY_NICE_STRING_H_

#include <iostream>
#include <vector>

class NaughtNiceStrings {
 public:
  NaughtNiceStrings();
  ~NaughtNiceStrings();
  void AddExceptionString(const std::string& str_excStr);
  void SetString(std::string str);
  bool DoesExcludeExceptions();
  bool AtLeast3Vowels();
  bool ContainsDoubleLetter();
  bool IsNiceString();

 protected:
  std::vector<std::string> _vec_excStrings;
  char* _pch_vowels;
  std::string _str_testString;
};

#endif //ADVENTOFCODE_2015_INC_DAY5_NAUGHTY_NICE_STRING_H_
