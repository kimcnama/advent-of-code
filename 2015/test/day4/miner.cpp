//
// Created by kieran McNamara on 16/12/2021.
//

#include <gtest/gtest.h>
#include "../../inc/day4/advent_coin_miner.h"

TEST(MineTest, Sanity) {
  const char* key = "bgvyzdsv";
  uint8_t nKey = 8;
  auto cls = AdventCoinMiner(key, nKey);
  cls.Mine(6);

  char* sol = cls.GetSolution();

  for (uint8_t i = 0; i < NBYTES_MD5; ++i) {
    std::cout << sol[i];
  }
  std::cout << std::endl << std::endl;
}