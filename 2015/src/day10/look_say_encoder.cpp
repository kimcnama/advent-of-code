//
// Created by kieran McNamara on 17/02/2022.
//

#include "../../inc/day10/look_say_encoder.h"

#define ASCII_0_DEC   (48)
#define ASCII_9_DEC   (57)

LookSayEncoder::LookSayEncoder() {
  _str_msg = "";
  _str_digest = "";
}
void LookSayEncoder::SetMessage(const std::string &str) {
  _str_msg = str;
  _str_digest = "";
}

static uint8_t ConvertCharString(const char& ch) {
  uint8_t u8_ch = ch;
  if (u8_ch < ASCII_0_DEC || u8_ch > ASCII_9_DEC) {
    return 0;
  }
  return u8_ch - ASCII_0_DEC;
}

static char ConvertIntChar(const uint8_t& u8) {
  return (char)(u8 + ASCII_0_DEC);
}

void LookSayEncoder::ProcessMessage() {
  uint8_t u8_ch;
  uint8_t u8_prevCh = 10;
  uint16_t u16_currchCount = 0;
  _str_digest = "";

  if (!_str_msg.empty()) {
    u8_prevCh = ConvertCharString(_str_msg.at(0));
  }

  for (auto & ch : _str_msg) {
    u8_ch = ConvertCharString(ch);

    if (u8_prevCh != u8_ch) {

      _str_digest += ConvertIntChar(u16_currchCount);
      _str_digest += ConvertIntChar(u8_prevCh);

      u16_currchCount = 1;
    } else {
      ++u16_currchCount;
    }

    u8_prevCh = u8_ch;
  }

  _str_digest += ConvertIntChar(u16_currchCount);
  _str_digest += ConvertIntChar(u8_prevCh);
}
std::string LookSayEncoder::GetDigest() {
  return _str_digest;
}
void LookSayEncoder::ProcessMessageNTimes(uint16_t u16_n) {
  std::string str_origMsg = _str_msg;
  for (uint16_t u16_i = 0; u16_i < u16_n; ++u16_i) {
    ProcessMessage();
    _str_msg = _str_digest;
  }
  _str_msg = str_origMsg;
}
uint32_t LookSayEncoder::GetDigestLength() {
  return _str_digest.size();
}

LookSayEncoder::~LookSayEncoder() = default;

