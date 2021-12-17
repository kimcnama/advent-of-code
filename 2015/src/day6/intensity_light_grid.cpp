//
// Created by kieran McNamara on 17/12/2021.
//

#include "../../inc/day6/intensity_light_grid.h"

IntensityLightGrid::IntensityLightGrid() {
  SetAll(0);
}

IntensityLightGrid::~IntensityLightGrid() = default;

void IntensityLightGrid::SetAll(uint16_t u16_val) {
  for (auto & x : _u16_lightGrid2D) {
    for (auto & y : x) {
      y = u16_val;
    }
  }
}

uint16_t IntensityLightGrid::SanitizeInput(uint16_t u16_input) {

  if (u16_input >= GRID_SZ) {
    return GRID_SZ - 1;
  }

  if (u16_input < 0) {
    return 0;
  }

  return u16_input;
}

void IntensityLightGrid::ModifyInRange(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, intensity_op op) {

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
          ++_u16_lightGrid2D[u16_x][u16_y];
          break;
        case OFF:
          if (_u16_lightGrid2D[u16_x][u16_y] > 0) {
            --_u16_lightGrid2D[u16_x][u16_y];
          }
          break;
        case TOGGLE:
          _u16_lightGrid2D[u16_x][u16_y] += 2;
          break;
        default:
          break;
      }

    }
  }

}

uint16_t IntensityLightGrid::GetValAtCoord(uint16_t x, uint16_t y) {
  return _u16_lightGrid2D[x][y];
}

uint64_t IntensityLightGrid::GetTotalBrightness() {
  uint64_t u64_totBrightness = 0;

  for (auto & x : _u16_lightGrid2D) {
    for (auto & y : x) {
      u64_totBrightness += y;
    }
  }

  return u64_totBrightness;
}
void IntensityLightGrid::PrintGrid() {
  int16_t u16_y = GRID_SZ - 1;

  std::cout << std::endl;

  do {

    for (uint16_t u16_x = 0; u16_x <= GRID_SZ - 1; ++u16_x) {
      std::cout << _u16_lightGrid2D[u16_x][u16_y];
    }

    std::cout << std::endl;
    --u16_y;
  } while (u16_y >= 0);

  std::cout << std::endl;
}


