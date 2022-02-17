//
// Created by kieran McNamara on 17/02/2022.
//

#ifndef ADVENTOFCODE_2015_INC_DAY10_LOOKSAYENCODER_H_
#define ADVENTOFCODE_2015_INC_DAY10_LOOKSAYENCODER_H_

#include <iostream>

class LookSayEncoder {
 public:
  LookSayEncoder();
  ~LookSayEncoder();
  void SetMessage(const std::string& str);
  void ProcessMessage();
  void ProcessMessageNTimes(uint16_t u16_n);
  std::string GetDigest();
  uint32_t GetDigestLength();

 protected:
  std::string _str_msg;
  std::string _str_digest;
};

#endif //ADVENTOFCODE_2015_INC_DAY10_LOOKSAYENCODER_H_
