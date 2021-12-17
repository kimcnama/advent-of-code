//
// Created by kieran McNamara on 17/12/2021.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day6/light_grid.h"

void IterateThroughGrid(LightGrid *cls, bool b_expVal) {
  for (uint16_t i = 0; i < GRID_SZ; ++i) {
    for (uint16_t j = 0; j < GRID_SZ; ++j) {
      ASSERT_EQ(cls->GetValAtCoord(i, j), b_expVal);
    }
  }
}

TEST(SanityTests, InitAndSet) {
  auto cls = LightGrid();
  IterateThroughGrid(&cls, false);

  cls.SetAll(true);
  IterateThroughGrid(&cls, true);

  cls.SetAll(false);
  IterateThroughGrid(&cls, false);
}

TEST(PrintGrid, InitAndSet) {
  auto cls = LightGrid();
  cls.ModifyInRange(1, 1, 2, 2, TOGGLE);
  cls.PrintGrid();
  cls.SetAll(true);
  cls.PrintGrid();
  cls.ModifyInRange(5, 5, 6, 6, OFF);
  cls.PrintGrid();
}

TEST(LightsOnTest, InitAndSet) {
  auto cls = LightGrid();

  uint8_t expectedOn = 4;
  ASSERT_EQ(cls.GetNLightsOn(), 0);
  cls.ModifyInRange(1, 1, 2, 2, TOGGLE);
  ASSERT_EQ(cls.GetNLightsOn(), expectedOn);
  cls.SetAll(true);
  ASSERT_EQ(cls.GetNLightsOn(), GRID_SZ * GRID_SZ);
  cls.ModifyInRange(5, 5, 6, 6, OFF);
  ASSERT_EQ(cls.GetNLightsOn(), (GRID_SZ * GRID_SZ) - expectedOn);

  cls.SetAll(false);
  cls.ModifyInRange(5, 5, 6, 6, ON);
}

TEST(LightGridTest, Sanity) {
  auto cls = LightGrid();
  cls.ModifyInRange(0, 0, 2, 2, ON);
  ASSERT_EQ(cls.GetNLightsOn(), 9);

  cls.SetAll(false);
  cls.ModifyInRange(5, GRID_SZ - 1, 5, 0, ON);
  ASSERT_EQ(cls.GetNLightsOn(), GRID_SZ);

  cls.SetAll(false);
  cls.ModifyInRange(499, 499, 500, 500, ON);
  ASSERT_EQ(cls.GetNLightsOn(), 4);
}

bool EraseSubStr(std::string & mainStr, const std::string & toErase)
{
  // Search for the substring in string
  size_t pos = mainStr.find(toErase);
  if (pos != std::string::npos)
  {
    // If found then erase it from string
    mainStr.erase(pos, toErase.length());
    return true;
  }
  return false;
}

uint16_t GetXFromCoordStr(std::string coord) {
  std::string str_x = coord.substr(0, coord.find_first_of(','));
  return (uint16_t)std::atoi(str_x.c_str());
}

uint16_t GetYFromCoordStr(std::string coord) {
  std::string str_y = coord.substr(coord.find_first_of(',') + 1);
  return (uint16_t)std::atoi(str_y.c_str());
}

TEST(LightGridTest, KnownInput) {

  std::string str_inputInstructions;
  std::ifstream file("../../../2015/test/day6/test_data.in.txt");
  std::string str_line;

  auto cls = LightGrid();

  std::string coords1 = "";
  std::string coords2 = "";
  std::string throughDelim = " through ";

  std::string toggle = "toggle ";
  std::string turnOn = "turn on ";
  std::string turnOff = "turn off ";
  operation op;

  uint16_t x1, x2, y1, y2;

  while(getline(file, str_line)) {

    std::cout << str_line << std::endl;

    if (EraseSubStr(str_line, toggle)) {
      op = TOGGLE;
    } else if (EraseSubStr(str_line, turnOn)) {
      op = ON;
    } else if (EraseSubStr(str_line, turnOff)) {
      op = OFF;
    } else {
      ASSERT_FALSE(true);
    }

    coords1 = str_line.substr(0, str_line.find_first_of(throughDelim));
    coords2 = str_line.substr(str_line.find_first_of(throughDelim) + throughDelim.size());
    x1 = GetXFromCoordStr(coords1);
    y1 = GetYFromCoordStr(coords1);
    x2 = GetXFromCoordStr(coords2);
    y2 = GetYFromCoordStr(coords2);

    switch (op) {
      case ON:
        cls.ModifyInRange(x1, y1, x2, y2, ON);
        break;
      case OFF:
        cls.ModifyInRange(x1, y1, x2, y2, OFF);
        break;
      case TOGGLE:
        cls.ModifyInRange(x1, y1, x2, y2, TOGGLE);
        break;
      default:
        ASSERT_FALSE(true);
        break;
    }

  }

  std::cout << "Number of lights lit: " << cls.GetNLightsOn() << std::endl;
  ASSERT_EQ(cls.GetNLightsOn(), 377891);
}