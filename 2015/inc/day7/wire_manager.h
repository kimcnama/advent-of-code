//
// Created by kieran McNamara on 19/12/2021.
//

#ifndef ADVENTOFCODE_2015_INC_DAY7_WIRE_MANAGER_H_
#define ADVENTOFCODE_2015_INC_DAY7_WIRE_MANAGER_H_

#include <map>
#include "wire.h"

enum bitwise_operation {AND, OR, NOT, LSHIFT, RSHIFT};

class WireManager {
 public:
  WireManager();
  ~WireManager();
  void PrintWireValues();
  void SetWire(const std::string& str_wireName, uint16_t u16_val);
  Wire* GetWire(const std::string& str_wireName);
  bool IsWireInMap(const std::string& str_wireName);
  void And(const std::string& str_dest, const std::string& str_w1, const std::string& str_w2);
  void Or(const std::string& str_dest, const std::string& str_w1, const std::string& str_w2);
  void Not(const std::string& str_dest, const std::string& str_w1);
  void LShift(const std::string& str_dest, const std::string& str_w1, uint16_t u16_n);
  void RShift(const std::string& str_dest, const std::string& str_w1, uint16_t u16_n);

  bool ExeInstructionLine(std::string& str_instruction);

  int NElementsMap();


 protected:
  std::map<std::string, Wire*> _map_wires;
};

#endif //ADVENTOFCODE_2015_INC_DAY7_WIRE_MANAGER_H_
