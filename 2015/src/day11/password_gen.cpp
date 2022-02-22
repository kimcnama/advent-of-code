//
// Created by kieran McNamara on 18/02/2022.
//

#include "../../inc/day11/password_gen.h"

#define PWD_LOWER_LIMIT   (97)
#define PWD_UPPER_LIMIT   (122)


PasswordGen::PasswordGen(const std::string& str_pwd) {
  _str_pwd = str_pwd;
  _str_nextpwd = str_pwd;
}

void PasswordGen::SetInitPassword(const std::string& str_pwd) {
  _str_pwd = str_pwd;
  _str_nextpwd = str_pwd;
}

void PasswordGen::IncrementPassword() {
  if (_str_nextpwd.empty()) {
    _str_nextpwd = _str_pwd;
  }

  uint8_t u8_ch;

  for (uint8_t u8_i = _str_nextpwd.size() - 1; u8_i >= 0; --u8_i) {
    if (_str_nextpwd.at(u8_i) < PWD_UPPER_LIMIT) {
      u8_ch = _str_nextpwd.at(u8_i);
      ++u8_ch;
      _str_nextpwd[u8_i] = u8_ch;
      return;
    } else {
      _str_nextpwd[u8_i] = PWD_LOWER_LIMIT;
    }
  }
}
std::string PasswordGen::GetNextPassword() {
  return _str_nextpwd;
}

void PasswordGen::ProcessNextPassword() {
  _str_nextpwd = _str_pwd;

  while (true) {
    this->IncrementPassword();
    if (this->ContainsIllegalLetters()) {
      continue;
    }
    if (!this->ContainsStraight()) {
      continue;
    }
    if (!this->Contains2NonOverlapDoubles()) {
      continue;
    }
    break;
  }
}

bool PasswordGen::ContainsIllegalLetters() {
  for (auto & ch : _str_nextpwd) {
    if (ch == 'i' || ch == 'o' || ch == 'l') {
      return true;
    }
  }
  return false;
}

bool PasswordGen::ContainsStraight() {

  uint8_t u8_ch;

  for (uint8_t u8_i = 0; u8_i < _str_nextpwd.size() - 3; ++u8_i) {
    u8_ch = _str_nextpwd.at(u8_i);
    if (_str_nextpwd.at(u8_i + 1) != u8_ch + 1) {
      continue;
    }
    if (_str_nextpwd.at(u8_i + 2) == u8_ch + 2) {
      return true;
    }
  }
  return false;
}
bool PasswordGen::Contains2NonOverlapDoubles() {

  uint8_t u8_ch;
  uint8_t u8_nDoubles = 0;

  for (uint8_t u8_i = 0; u8_i < _str_nextpwd.size() - 1; ++u8_i) {
    if (_str_nextpwd.at(u8_i) == _str_nextpwd.at(u8_i + 1)) {
      ++u8_nDoubles;
      ++u8_i;
    }
  }

  return u8_nDoubles >= 2;
}
