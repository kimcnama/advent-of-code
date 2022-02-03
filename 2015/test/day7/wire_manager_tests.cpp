//
// Created by kieran McNamara on 19/12/2021.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day7/wire_manager.h"

TEST(WireManagerTest, SanityTests) {

  auto cls = WireManager();

  cls.SetWire("x", 123);
  cls.SetWire("y", 456);

  cls.And("d", "x", "y");
  cls.Or("e", "x", "y");
  cls.LShift("f", "x", 2);
  cls.RShift("g", "y", 2);
  cls.Not("h", "x");
  cls.Not("i", "y");

  cls.PrintWireValues();
}

TEST(WireManagerInstructionParse, SanityTests) {

  auto cls = WireManager();

  std::string instruction = "123 -> x";
  cls.ExeInstructionLine(instruction);

  instruction = "456 -> y";
  cls.ExeInstructionLine(instruction);

  instruction = "x AND y -> d";
  cls.ExeInstructionLine(instruction);

  instruction = "x OR y -> e";
  cls.ExeInstructionLine(instruction);

  instruction = "x LSHIFT 2 -> f";
  cls.ExeInstructionLine(instruction);

  instruction = "y RSHIFT 2 -> g";
  cls.ExeInstructionLine(instruction);

  instruction = "NOT x -> h";
  cls.ExeInstructionLine(instruction);

  instruction = "NOT y -> i";
  cls.ExeInstructionLine(instruction);

  cls.PrintWireValues();
}

TEST(WireManagerTest, KnownInput) {

  std::ifstream file("../../../2015/test/day7/test_data.in.txt");
  std::string str_line;

  auto cls = WireManager();

  std::vector<std::string> outstandingIns;

  while(getline(file, str_line)) {
    if (!cls.ExeInstructionLine(str_line)) {
      outstandingIns.push_back(str_line);
    }
  }

  uint16_t u16_i = 0;
  while(outstandingIns.size() > 0) {
    str_line = outstandingIns.at(u16_i);

    if (cls.ExeInstructionLine(str_line)) {
      outstandingIns.erase(outstandingIns.begin() + u16_i);
    }

    ++u16_i;
    if (u16_i >= outstandingIns.size()) {
      u16_i = 0;
    }
  }

  cls.PrintWireValues();
  Wire* a = cls.GetWire("a");
  ASSERT_EQ(a->GetSignalVal(), 956);
}

TEST(WireManagerTest, KnownInputPart2) {

  // Must remove the "-> b" line in input txt file to get answer
  std::ifstream file("../../../2015/test/day7/test_data.in.txt");
  std::string str_line;

  auto cls = WireManager();

  std::vector<std::string> outstandingIns, orderedIns;

  cls.SetWire("b", 956);

  while(getline(file, str_line)) {
    if (!cls.ExeInstructionLine(str_line)) {
      outstandingIns.push_back(str_line);
    } else {
      orderedIns.push_back(str_line);
    }
  }

  uint16_t u16_i = 0;
  while(outstandingIns.size() > 0) {
    str_line = outstandingIns.at(u16_i);

    if (cls.ExeInstructionLine(str_line)) {
      outstandingIns.erase(outstandingIns.begin() + u16_i);
      orderedIns.push_back(str_line);
    }

    ++u16_i;
    if (u16_i >= outstandingIns.size()) {
      u16_i = 0;
    }
  }

  cls.PrintWireValues();
//  cls.ResetWires(0);
  cls.SetWire("b", 956);
  cls.PrintWireValues();

  for (auto & str_ins : orderedIns) {
    cls.ExeInstructionLine(str_ins);
  }

  cls.PrintWireValues();
  Wire* a = cls.GetWire("a");
  ASSERT_EQ(a->GetSignalVal(), 40149);
}