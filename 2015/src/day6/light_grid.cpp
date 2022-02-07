//
// Created by kieran McNamara on 17/12/2021.
//

#include "../../inc/day6/light_grid.h"

LightGrid::LightGrid() {
  SetAll(false);
}

void LightGrid::SetAll(bool b_val) {
  for (auto & parrb_x : _b_lightGrid2D) {
    for (bool & parrb_y : parrb_x) {
      parrb_y = b_val;
    }
  }
}

void LightGrid::ModifyInRange(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, operation op) {

  uint16_t u16_maxX, u16_maxY, u16_minX, u16_minY;

  if (x1 < x2) {
    u16_minX = SanitizeInput(x1);
    u16_maxX = SanitizeInput(x2);
  } else {
    u16_minX = SanitizeInput(x2);
    u16_maxX = SanitizeInput(x1);
  }

  if (y1 < y2) {
    u16_minY = SanitizeInput(y1);
    u16_maxY = SanitizeInput(y2);
  } else {
    u16_minY = SanitizeInput(y2);
    u16_maxY = SanitizeInput(y1);
  }

  for (uint16_t u16_x = u16_minX; u16_x <= u16_maxX; ++u16_x) {
    for (uint16_t u16_y = u16_minY; u16_y <= u16_maxY; ++u16_y) {

      switch (op) {
        case ON:
          _b_lightGrid2D[u16_x][u16_y] = true;
          break;
        case OFF:
          _b_lightGrid2D[u16_x][u16_y] = false;
          break;
        case TOGGLE:
          _b_lightGrid2D[u16_x][u16_y] = !_b_lightGrid2D[u16_x][u16_y];
          break;
        default:
          break;
      }

    }
  }

}

bool LightGrid::GetValAtCoord(uint16_t x, uint16_t y) {
  return _b_lightGrid2D[x][y];
}

uint16_t LightGrid::SanitizeInput(uint16_t u16_input) {

  if (u16_input >= GRID_SZ) {
    return GRID_SZ - 1;
  }

  if (u16_input < 0) {
    return 0;
  }

  return u16_input;
}
void LightGrid::PrintGrid() {

  int16_t u16_y = GRID_SZ - 1;

  std::cout << std::endl;

  do {

    for (uint16_t u16_x = 0; u16_x <= GRID_SZ - 1; ++u16_x) {
      std::cout << _b_lightGrid2D[u16_x][u16_y];
    }

    std::cout << std::endl;
    --u16_y;
  } while (u16_y >= 0);

  std::cout << std::endl;
}
uint32_t LightGrid::GetNLightsOn() {
  uint32_t u32_n = 0;
  for (auto & parrb_x : _b_lightGrid2D) {
    for (bool & parrb_y : parrb_x) {
      if (parrb_y) {
        ++u32_n;
      }
    }
  }

  return u32_n;
}

LightGrid::~LightGrid() = default;



