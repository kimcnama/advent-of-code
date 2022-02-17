//
// Created by kieran McNamara on 17/02/2022.
//

#include <gtest/gtest.h>
#include "../../inc/day10/look_say_encoder.h"

static void SetAndTest(LookSayEncoder* cls, const std::string& msg, const std::string& expDigest) {
  cls->SetMessage(msg);
  ASSERT_EQ(cls->GetDigest(), "");
  cls->ProcessMessage();
  ASSERT_EQ(cls->GetDigest(), expDigest);
}

TEST(LookSayEncoderTests, SanityTests) {

  auto target = LookSayEncoder();

  ASSERT_EQ(target.GetDigest(), "");

  SetAndTest(&target, "1", "11");
  SetAndTest(&target, "11", "21");
  SetAndTest(&target, "21", "1211");
  SetAndTest(&target, "1211", "111221");
  SetAndTest(&target, "111221", "312211");
}

TEST(LookSayEncoderTests, KnownInputTest) {

  auto target = LookSayEncoder();
  target.SetMessage("1113122113");
  target.ProcessMessageNTimes(40);
  std::cout << "Digest Length: " << target.GetDigestLength() << std::endl;

  ASSERT_EQ(target.GetDigestLength(), 360154);
}