//
// Created by kieran McNamara on 10/02/2022.
//

#ifndef ADVENTOFCODE_2015_INC_DAY8_CHARACTER_MEMORY_SERVICE_H_
#define ADVENTOFCODE_2015_INC_DAY8_CHARACTER_MEMORY_SERVICE_H_

#include <string>
#include <cstdint>

class CharacterMemoryService {
 public:
  CharacterMemoryService();
  ~CharacterMemoryService();
  void Reset();
  void ProcessString(std::string str);

 protected:

  uint16_t _u16_nCharsCode;
  uint16_t _u16_nCharsMem;
  uint16_t _u16_nCharsDiff;
};

#endif //ADVENTOFCODE_2015_INC_DAY8_CHARACTER_MEMORY_SERVICE_H_
