//
// Created by kieran McNamara on 16/12/2021.
//

#include "../../inc/day5/naughty_nice_string.h"

#include <utility>

#define N_VOWELS  5

NaughtNiceStrings::NaughtNiceStrings() {
  _str_testString.clear();
  _vec_excStrings.clear();
  _pch_vowels = new char[N_VOWELS];
  _pch_vowels[0] = 'a';
  _pch_vowels[1] = 'e';
  _pch_vowels[2] = 'i';
  _pch_vowels[3] = 'o';
  _pch_vowels[4] = 'u';
}

NaughtNiceStrings::~NaughtNiceStrings() {
  free(_pch_vowels);
}
bool NaughtNiceStrings::ContainsDoubleLetter() {
  for (uint8_t u8_i = 1; u8_i < _str_testString.size(); ++u8_i) {
    if ( _str_testString.at(u8_i - 1) == _str_testString.at(u8_i)) {
      return true;
    }
  }
  return false;
}

bool NaughtNiceStrings::DoesExcludeExceptions() {
  for (auto & str_subStr : _vec_excStrings) {
    if (_str_testString.find(str_subStr) != std::string::npos) {
      return false;
    }
  }
  return true;
}

bool NaughtNiceStrings::AtLeast3Vowels() {
  uint16_t u16_vowelCount = 0;
  for (auto & ch : _str_testString) {
    for (uint8_t u8_i = 0; u8_i < N_VOWELS; ++u8_i) {
      if (ch == _pch_vowels[u8_i]) {
        ++u16_vowelCount;
        continue;
      }
    }
  }
  return u16_vowelCount >= 3;
}

void NaughtNiceStrings::AddExceptionString(const std::string& str_excStr) {
  _vec_excStrings.push_back(str_excStr);
}
void NaughtNiceStrings::SetString(std::string str) {
  _str_testString = std::move(str);
}
bool NaughtNiceStrings::IsNiceString() {
  return this->ContainsDoubleLetter() && this->DoesExcludeExceptions() && this->AtLeast3Vowels();
}



