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

  while(getline(file, str_line)) {
    cls.ExeInstructionLine(str_line);
  }

  cls.PrintWireValues();
}