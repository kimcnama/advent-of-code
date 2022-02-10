//
// Created by kieran McNamara on 10/02/2022.
//

#include "../../inc/day8/character_memory_service.h"

CharacterMemoryService::CharacterMemoryService() {
  this->Reset();
}
void CharacterMemoryService::Reset() {
  this->_u16_nCharsCode = 0;
  this->_u16_nCharsMem = 0;
  this->_u16_nCharsDiff = 0;
}

void CharacterMemoryService::ProcessString(std::string str) {

  char ch, ch2;
  uint16_t u16_charsCode = 0;
  uint16_t u16_charsMem = 0;

  for (uint16_t u16_i = 0; u16_i < str.size(); ++u16_i) {
    ch = str.at(u16_i);
  }

  this->_u16_nCharsDiff = abs(this->_u16_nCharsCode - this->_u16_nCharsMem);
}

CharacterMemoryService::~CharacterMemoryService() = default;

