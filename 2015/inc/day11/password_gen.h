//
// Created by kieran McNamara on 18/02/2022.
//

#ifndef ADVENTOFCODE_2015_INC_DAY11_PASSWORD_GEN_H_
#define ADVENTOFCODE_2015_INC_DAY11_PASSWORD_GEN_H_

#include <iostream>

class PasswordGen {
 public:
  PasswordGen(const std::string& str_pwd);
  void SetInitPassword(const std::string& str_pwd);
  void ProcessNextPassword();
  void IncrementPassword();
  std::string GetNextPassword();

  bool ContainsIllegalLetters();
  bool Contains2NonOverlapDoubles();
  bool ContainsStraight();
 protected:
  std::string _str_pwd;
  std::string _str_nextpwd;
};

#endif //ADVENTOFCODE_2015_INC_DAY11_PASSWORD_GEN_H_
