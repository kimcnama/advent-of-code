//
// Created by kieran McNamara on 14/02/2022.
//

#include "../../inc/day8/reverse_encoder.h"

ReverseEncoder::ReverseEncoder() : CharacterMemoryService() {
  this->_u16_nCharsInflated = 0;
}
void ReverseEncoder::ProcessString(const std::string &str) {
  CharacterMemoryService::ProcessString(str);

  char ch;
  uint16_t u16_nCharInflatedRepr = str.size();
  for (uint16_t u16_i = 0; u16_i < str.size(); ++u16_i) {
    ch = str.at(u16_i);
    if (ch == QUOTATION_CHAR && (u16_i == 0 || u16_i == str.size() - 1)) {
      u16_nCharInflatedRepr += 2;
    } else if (ch == QUOTATION_CHAR || ch == ESCAPE_CHAR) {
      ++u16_nCharInflatedRepr;
    }
  }
  this->_u16_nCharsInflated += u16_nCharInflatedRepr;
  this->_u16_nCharsInfCodeDiff = abs(this->_u16_nCharsInflated - this->_u16_nCharsCode);
}

void ReverseEncoder::Reset() {
  CharacterMemoryService::Reset();
  _u16_nCharsInflated = 0;
  _u16_nCharsInfCodeDiff = 0;
}

uint16_t ReverseEncoder::GetNCodeInflReprDiff() {
  return _u16_nCharsInfCodeDiff;
}

uint16_t ReverseEncoder::GetNCodeInflatedRepr() {
  return _u16_nCharsInflated;
}
