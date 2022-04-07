//
// Created by kieran McNamara on 06/03/2022.
//

#include "../../inc/day12/json_summer.h"

#define CHAR_MINUS    ('-')

JsonSummer::JsonSummer() {
  _i32_sum = 0;
}

JsonSummer::~JsonSummer() = default;

int32_t JsonSummer::GetSum() {
  return _i32_sum;
}
void JsonSummer::ProcessJson(const std::string& str_json) {
  _i32_sum = 0;
  std::string str_num;
  bool b_prevDigit = false;

  for (const char& ch : str_json) {

    if (isdigit(ch) || ch == CHAR_MINUS) {

      str_num.push_back(ch);
      b_prevDigit = true;

    } else if (b_prevDigit) {

      if (!str_num.empty()) {
        _i32_sum += std::stoi(str_num);
      }

      b_prevDigit = false;
      str_num = "";

    }

  }
}
