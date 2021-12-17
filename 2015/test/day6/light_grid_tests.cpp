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

}

TEST(LightGridTest, KnownInput) {

}