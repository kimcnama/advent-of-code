//
// Created by kieran McNamara on 17/12/2021.
//

#ifndef ADVENTOFCODE_2015_INC_DAY6_INTENSITY_LIGHT_GRID_H_
#define ADVENTOFCODE_2015_INC_DAY6_INTENSITY_LIGHT_GRID_H_

#include <iostream>

#define GRID_SZ   1000

enum intensity_op { ON, OFF, TOGGLE };

class IntensityLightGrid {
 public:
  IntensityLightGrid();
  ~IntensityLightGrid();
  void SetAll(uint16_t u16_val);
  void ModifyInRange(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, intensity_op op);
  uint16_t GetValAtCoord(uint16_t x, uint16_t y);
  uint64_t GetTotalBrightness();
  void PrintGrid();

 protected:
  static uint16_t SanitizeInput(uint16_t u16_input);
  uint16_t _u16_lightGrid2D[GRID_SZ][GRID_SZ];
};

#endif //ADVENTOFCODE_2015_INC_DAY6_INTENSITY_LIGHT_GRID_H_
