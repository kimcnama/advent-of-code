//
// Created by kieran McNamara on 17/12/2021.
//

#ifndef ADVENTOFCODE_2015_INC_DAY6_LIGHT_GRID_H_
#define ADVENTOFCODE_2015_INC_DAY6_LIGHT_GRID_H_

#include <iostream>

enum operation { ON, OFF, TOGGLE };

#define GRID_SZ   1000

class LightGrid {
 public:
  LightGrid();
  ~LightGrid();
  void SetAll(bool b_val);
  void ModifyInRange(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, operation op);
  bool GetValAtCoord(uint16_t x, uint16_t y);
  uint32_t GetNLightsOn();
  void PrintGrid();

 protected:
  static uint16_t SanitizeInput(uint16_t u16_input);
  bool _b_lightGrid2D[GRID_SZ][GRID_SZ];
};

#endif //ADVENTOFCODE_2015_INC_DAY6_LIGHT_GRID_H_
