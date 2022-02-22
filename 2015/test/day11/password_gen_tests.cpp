//
// Created by kieran McNamara on 22/02/2022.
//


#include <gtest/gtest.h>
#include "../../inc/day11/password_gen.h"

static uint32_t lowerCaseRange = 122 - 97 + 1;

static void IncrementPwdNTimes(PasswordGen* target, uint32_t u32_n) {
  for (uint32_t i = 0; i < u32_n; ++i) {
    target->IncrementPassword();
  }
}

TEST(PasswordGenTests, IncrementPassword) {

  std::string pwd = "aaaaaaaa";
  auto target = PasswordGen(pwd);

  target.IncrementPassword();
  ASSERT_EQ(target.GetNextPassword(), "aaaaaaab");

  IncrementPwdNTimes(&target, lowerCaseRange - 2);
  ASSERT_EQ(target.GetNextPassword(), "aaaaaaaz");

  target.IncrementPassword();
  ASSERT_EQ(target.GetNextPassword(), "aaaaaaba");

  IncrementPwdNTimes(&target, lowerCaseRange - 1);
  ASSERT_EQ(target.GetNextPassword(), "aaaaaabz");
  target.IncrementPassword();
  ASSERT_EQ(target.GetNextPassword(), "aaaaaaca");

  IncrementPwdNTimes(&target, lowerCaseRange);
  ASSERT_EQ(target.GetNextPassword(), "aaaaaada");
  IncrementPwdNTimes(&target, lowerCaseRange);
  ASSERT_EQ(target.GetNextPassword(), "aaaaaaea");

  IncrementPwdNTimes(&target, lowerCaseRange * 21);
  ASSERT_EQ(target.GetNextPassword(), "aaaaaaza");

  IncrementPwdNTimes(&target, lowerCaseRange - 1);
  ASSERT_EQ(target.GetNextPassword(), "aaaaaazz");

  target.IncrementPassword();
  ASSERT_EQ(target.GetNextPassword(), "aaaaabaa");

  IncrementPwdNTimes(&target, lowerCaseRange * lowerCaseRange);
  ASSERT_EQ(target.GetNextPassword(), "aaaaacaa");

  IncrementPwdNTimes(&target, lowerCaseRange * lowerCaseRange * (lowerCaseRange - 2));
  ASSERT_EQ(target.GetNextPassword(), "aaaabaaa");

  target.SetInitPassword("yzzzzzzz");
  target.IncrementPassword();
  ASSERT_EQ(target.GetNextPassword(), "zaaaaaaa");
}

TEST(PasswordGenTests, ConditionTests) {

  auto target = PasswordGen("aaaaaaaa");
  target.SetInitPassword("hijklmmn");
  ASSERT_TRUE(target.ContainsStraight());
  ASSERT_TRUE(target.ContainsIllegalLetters());

  target.SetInitPassword("abbceffg");
  ASSERT_TRUE(target.Contains2NonOverlapDoubles());
  ASSERT_FALSE(target.ContainsStraight());

  target.SetInitPassword("abbcegjk");
  ASSERT_FALSE(target.Contains2NonOverlapDoubles());

  target.SetInitPassword("acccegjk");
  ASSERT_FALSE(target.Contains2NonOverlapDoubles());
  target.SetInitPassword("acccegbb");
  ASSERT_TRUE(target.Contains2NonOverlapDoubles());

  target.SetInitPassword("abcdffaa");
  ASSERT_TRUE(target.Contains2NonOverlapDoubles());
}

TEST(PasswordGenTests, NextPasswordTest) {

  auto target = PasswordGen("abcdefgh");
  target.ProcessNextPassword();
  ASSERT_EQ(target.GetNextPassword(), "abcdffaa");

  target.SetInitPassword("ghijklmn");
  target.ProcessNextPassword();
  ASSERT_EQ(target.GetNextPassword(), "ghjaabcc");

  target.SetInitPassword("cqjxjnds");
  target.ProcessNextPassword();
  ASSERT_EQ(target.GetNextPassword(), "cqjxxyzz");
}