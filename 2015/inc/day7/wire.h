//
// Created by kieran McNamara on 19/12/2021.
//

#ifndef ADVENTOFCODE_2015_INC_DAY7_WIRE_H_
#define ADVENTOFCODE_2015_INC_DAY7_WIRE_H_

#include <cstdint>

class Wire {
 public:
  explicit Wire(uint16_t u16_sig);
  ~Wire();
  uint16_t GetSignalVal();
  void SetSignalVal(uint16_t u16_sig);
  void And(Wire* w1, Wire* w2);
  void Or(Wire* w1, Wire* w2);
  void Not(Wire* w1);
  void LShift(Wire* w1, uint16_t u16_n);
  void RShift(Wire* w1, uint16_t u16_n);
 protected:
  uint16_t _u16_signal;
};

#endif //ADVENTOFCODE_2015_INC_DAY7_WIRE_H_
