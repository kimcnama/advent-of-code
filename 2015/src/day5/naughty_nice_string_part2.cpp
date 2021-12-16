//
// Created by kieran McNamara on 16/12/2021.
//

#include "../../inc/day5/naughty_nice_string_part2.h"

NaughtNiceStrings2::NaughtNiceStrings2() {
  _str_testString = "";
}

void NaughtNiceStrings2::SetString(std::string str) {
  _str_testString = std::move(str);
}

NaughtNiceStrings2::~NaughtNiceStrings2() = default;

bool NaughtNiceStrings2::ContainsDuo() {
  std::string str_temp, str_subStr;
  uint16_t u16_chInd1, u16_chInd2;

  if (_str_testString.size() < 4) {
    return false;
  }

  for (uint16_t u16_i = 0; u16_i < _str_testString.size() - 1; ++u16_i) {

    u16_chInd1 = u16_i;
    u16_chInd2 = u16_i + 1;
    str_temp = "";
    str_subStr = "";

    for (uint16_t u16_j = 0; u16_j < _str_testString.size(); ++u16_j) {

      if (u16_j != u16_chInd1 && u16_j != u16_chInd2) {

        if (u16_chInd1 == 1 && u16_j == 0) {
          continue;
        } else if (u16_chInd2 == _str_testString.size() - 2 && u16_j == _str_testString.size() - 1) {
          continue;
        }

        str_temp += _str_testString.at(u16_j);
      } else {
        str_subStr += _str_testString.at(u16_j);
      }
    }

    if (str_temp.find(str_subStr) != std::string::npos) {
      return true;
    }
  }

  return false;
}
bool NaughtNiceStrings2::HasReccuringCharWithDelim() {
  for (uint16_t u16_i = 2; u16_i < _str_testString.size(); ++u16_i) {
    if (_str_testString.at(u16_i - 2) == _str_testString.at(u16_i)) {
      return true;
    }
  }
  return false;
}
bool NaughtNiceStrings2::IsNiceString() {
  return this->HasReccuringCharWithDelim() && this->ContainsDuo();
}


