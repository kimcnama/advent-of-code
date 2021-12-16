//
// Created by kieran McNamara on 16/12/2021.
//

#include <gtest/gtest.h>
#include "../../inc/day4/advent_coin_miner.h"

void AssertEqual(char* v1, char* v2) {
  for (uint8_t i = 0; i < NBYTES_MD5; ++i) {
    if (v1[i] == '\0') {
      return;
    }
    ASSERT_EQ(v1[i], v2[i]);
  }
}

TEST(MinerLogicTests, IncrementNonce) {
  const char* key = "abcdef";
  uint8_t nKey = 6;
  auto cls = AdventCoinMiner(key, nKey);

  AssertEqual(cls.GetMessage(), "abcdef");

  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef1");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef2");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef3");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef4");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef5");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef6");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef7");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef8");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef9");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef10");
  cls.IncrementNonce();
  AssertEqual(cls.GetMessage(), "abcdef11");

  for (uint16_t i = 0; i < 100; ++i) {
    cls.IncrementNonce();
  }
  AssertEqual(cls.GetMessage(), "abcdef111");

  for (uint16_t i = 0; i < 1000; ++i) {
    cls.IncrementNonce();
  }
  AssertEqual(cls.GetMessage(), "abcdef1111");
}
