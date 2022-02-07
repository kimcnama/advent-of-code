//
// Created by kieran McNamara on 16/12/2021.
//

#ifndef ADVENTOFCODE_2015_INC_DAY5_NAUGHTY_NICE_STRING_PART2_H_
#define ADVENTOFCODE_2015_INC_DAY5_NAUGHTY_NICE_STRING_PART2_H_

#include <iostream>

class NaughtNiceStrings2 {
 public:
  NaughtNiceStrings2();
  ~NaughtNiceStrings2();
  void SetString(std::string str);
  bool ContainsDuo();
  bool HasReccuringCharWithDelim();
  bool IsNiceString();

 protected:
  std::string _str_testString;
};

#endif //ADVENTOFCODE_2015_INC_DAY5_NAUGHTY_NICE_STRING_PART2_H_
