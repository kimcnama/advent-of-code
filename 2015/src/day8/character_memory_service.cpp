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

void CharacterMemoryService::ProcessString(const std::string& str) {
  char ch;
  uint16_t u16_charsCode = 0;
  uint16_t u16_charsMem = 0;

  this->_u16_nCharsCode += str.size();

  for (uint16_t u16_i = 0; u16_i < str.size(); ++u16_i) {
    ch = str.at(u16_i);

    if (ch == ESCAPE_CHAR) {
      ++u16_i;

      if (u16_i == str.size()) {
        break;
      }
      ch = str.at(u16_i);

      switch (ch) {
        case ESCAPE_CHAR:
          ++this->_u16_nCharsMem;
          continue;
        case QUOTATION_CHAR:
          ++this->_u16_nCharsMem;
          continue;
        case 'x':
          ++this->_u16_nCharsMem;
          u16_i += 2;
          continue;
        default:
          break;
      }

    }

    if (ch == QUOTATION_CHAR) {
      continue;
    }

    ++this->_u16_nCharsMem;
  }


  this->_u16_nCharsDiff = abs(this->_u16_nCharsCode - this->_u16_nCharsMem);
}
uint16_t CharacterMemoryService::GetNMemoryChars() {
  return this->_u16_nCharsMem;
}
uint16_t CharacterMemoryService::GetNCharsDiff() {
  return this->_u16_nCharsDiff;
}
uint16_t CharacterMemoryService::GetNCodeChars() {
  return this->_u16_nCharsCode;
}

CharacterMemoryService::~CharacterMemoryService() = default;

