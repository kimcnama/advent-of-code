//
// Created by kieran McNamara on 15/12/2021.
//

#include <gtest/gtest.h>
#include "../../inc/day4/md5_wrapper.h"

void AssertEqual(char* v1, char* v2, uint8_t nBytes) {
  for (uint8_t i = 0; i < nBytes; ++i) {
    ASSERT_EQ(v1[i], v2[i]);
  }
}

TEST(MD5Tests, SanityTests) {
  const char* message = "abcdef609043";
  char digest[16];
  MD5Wrapper(message, digest);
  char expected[] = "000001DBBFA";
  AssertEqual(digest, expected, 11);

  const char* message1 = "pqrstuv1048970";
  char digest1[16];
  MD5Wrapper(message1, digest1);
  char expected1[] = "000006136EF";
  AssertEqual(digest1, expected1, 11);
}

TEST(AdventMinerTests, SanityTests) {
  const char* example1 = "abcdef609043";
  const char* example2 = "pqrstuv1048970";
  const char* example3 = "pqrstuv1048971";
  ASSERT_TRUE(AdventMiner(example1, 5));
  ASSERT_TRUE(AdventMiner(example2, 5));
  ASSERT_FALSE(AdventMiner(example3, 5));
}

