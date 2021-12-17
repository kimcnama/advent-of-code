//
// Created by kieran McNamara on 17/12/2021.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day6/intensity_light_grid.h"

void IterateThroughGrid(IntensityLightGrid *cls, uint16_t b_expVal) {
  for (uint16_t i = 0; i < GRID_SZ; ++i) {
    for (uint16_t j = 0; j < GRID_SZ; ++j) {
      ASSERT_EQ(cls->GetValAtCoord(i, j), b_expVal);
    }
  }
}

TEST(SanityTests, InitAndSet) {
  auto cls = IntensityLightGrid();
  IterateThroughGrid(&cls, 0);


}