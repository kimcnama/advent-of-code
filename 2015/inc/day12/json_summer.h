//
// Created by kieran McNamara on 06/03/2022.
//

#ifndef ADVENTOFCODE_2015_INC_DAY12_JSON_SUMMER_H_
#define ADVENTOFCODE_2015_INC_DAY12_JSON_SUMMER_H_

#include <cstdint>
#include <string>

class JsonSummer {
 public:
  JsonSummer();
  ~JsonSummer();
  int GetSum();
  void ProcessJson(const std::string& str_json);

 protected:
  int _i32_sum;
};

#endif //ADVENTOFCODE_2015_INC_DAY12_JSON_SUMMER_H_
