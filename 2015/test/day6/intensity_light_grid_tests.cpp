//
// Created by kieran McNamara on 17/12/2021.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day6/intensity_light_grid.h"

void IterateThroughIntensityGrid(IntensityLightGrid *cls, uint16_t b_expVal) {
  for (uint16_t i = 0; i < GRID_SZ; ++i) {
    for (uint16_t j = 0; j < GRID_SZ; ++j) {
      ASSERT_EQ(cls->GetValAtCoord(i, j), b_expVal);
    }
  }
}

TEST(IntesityLightGrid, InitAndSet) {

  auto cls = IntensityLightGrid();

  for (uint16_t u16_intensity = 0; u16_intensity < 10; ++u16_intensity) {
    cls.SetAll(u16_intensity);
    IterateThroughIntensityGrid(&cls, u16_intensity);
    ASSERT_EQ(cls.GetTotalBrightness(), GRID_SZ * GRID_SZ * u16_intensity);
  }
}

bool EraseSubStrI(std::string & mainStr, const std::string & toErase)
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

uint16_t GetXFromCoordStrI(std::string coord) {
  std::string str_x = coord.substr(0, coord.find_first_of(','));
  return (uint16_t)std::atoi(str_x.c_str());
}

uint16_t GetYFromCoordStrI(std::string coord) {
  std::string str_y = coord.substr(coord.find_first_of(',') + 1);
  return (uint16_t)std::atoi(str_y.c_str());
}

TEST(IntensityLightGridTest, KnownInput) {

  std::string str_inputInstructions;
  std::ifstream file("../../../2015/test/day6/test_data.in.txt");
  std::string str_line;

  auto cls = IntensityLightGrid();

  std::string coords1 = "";
  std::string coords2 = "";
  std::string throughDelim = " through ";

  std::string toggle = "toggle ";
  std::string turnOn = "turn on ";
  std::string turnOff = "turn off ";
  intensity_op op;

  uint16_t x1, x2, y1, y2;

  while(getline(file, str_line)) {

    std::cout << str_line << std::endl;

    if (EraseSubStrI(str_line, toggle)) {
      op = TOGGLE;
    } else if (EraseSubStrI(str_line, turnOn)) {
      op = ON;
    } else if (EraseSubStrI(str_line, turnOff)) {
      op = OFF;
    } else {
      ASSERT_FALSE(true);
    }

    coords1 = str_line.substr(0, str_line.find_first_of(throughDelim));
    coords2 = str_line.substr(str_line.find_first_of(throughDelim) + throughDelim.size());
    x1 = GetXFromCoordStrI(coords1);
    y1 = GetYFromCoordStrI(coords1);
    x2 = GetXFromCoordStrI(coords2);
    y2 = GetYFromCoordStrI(coords2);

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

  std::cout << "Total Brightness: " << cls.GetTotalBrightness() << std::endl;
  ASSERT_EQ(cls.GetTotalBrightness(), 14110788);
}