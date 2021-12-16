//
// Created by kieran McNamara on 16/12/2021.
//

#include <gtest/gtest.h>
#include "../../inc/day4/advent_coin_miner.h"

void AssertEqual(char* v1, char* v2) {
  for (uint8_t i = 0; i < NBYTES_MD5; ++i) {
    ASSERT_EQ(v1[i], v2[i]);
  }
}

TEST(MinerLogicTests, IncrementNonce) {
  const char* key = "abcdef";
  uint8_t nKey = 6;
  auto cls = AdventCoinMiner(key, nKey);

  AssertEqual(cls.GetMessage(), "abcdef0000000000");

  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef1000000000");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef2000000000");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef3000000000");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef4000000000");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef5000000000");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef6000000000");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef7000000000");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef8000000000");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef9000000000");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef0100000000");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef1100000000");

  for (uint16_t i = 0; i < 100; ++i) {
    cls.IncrementNonce();
  }
  AssertEqual(cls.GetMessage(), "abcdef1110000000");

  for (uint16_t i = 0; i < 1000; ++i) {
    cls.IncrementNonce();
  }
  AssertEqual(cls.GetMessage(), "abcdef1111000000");
}
