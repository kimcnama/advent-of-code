//
// Created by kieran McNamara on 10/02/2022.
//

#ifndef ADVENTOFCODE_2015_INC_DAY8_CHARACTER_MEMORY_SERVICE_H_
#define ADVENTOFCODE_2015_INC_DAY8_CHARACTER_MEMORY_SERVICE_H_

#include <string>
#include <cstdint>

#define ESCAPE_CHAR     '\\'
#define QUOTATION_CHAR  '"'

class CharacterMemoryService {
 public:
  CharacterMemoryService();
  ~CharacterMemoryService();
  virtual void Reset();
  virtual void ProcessString(const std::string& str);
  uint16_t GetNCodeChars();
  uint16_t GetNMemoryChars();
  uint16_t GetNCharsDiff();

 protected:
  uint16_t _u16_nCharsCode;
  uint16_t _u16_nCharsMem;
  uint16_t _u16_nCharsDiff;
};

#endif //ADVENTOFCODE_2015_INC_DAY8_CHARACTER_MEMORY_SERVICE_H_
