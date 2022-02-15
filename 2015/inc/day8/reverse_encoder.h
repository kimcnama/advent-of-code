//
// Created by kieran McNamara on 14/02/2022.
//

#ifndef ADVENTOFCODE_2015_INC_DAY8_REVERSE_ENCODER_H_
#define ADVENTOFCODE_2015_INC_DAY8_REVERSE_ENCODER_H_

#include "character_memory_service.h"

class ReverseEncoder : public CharacterMemoryService {
 public:
  ReverseEncoder();
  void ProcessString(const std::string& str);
  uint16_t GetNCodeInflatedRepr();
  uint16_t GetNCodeInflReprDiff();
  void Reset();

 protected:
  uint16_t _u16_nCharsInflated;
  uint16_t _u16_nCharsInfCodeDiff;
};

#endif //ADVENTOFCODE_2015_INC_DAY8_REVERSE_ENCODER_H_
