//
// Created by kieran McNamara on 14/02/2022.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day8/reverse_encoder.h"

static void AssertStringBytes(ReverseEncoder* cls,const std::string& str, const uint16_t& u16_expNCodeChars,
                              const uint16_t& u16_expNMemChars, const uint16_t& u16_expNInfChars) {

  cls->ProcessString(str);
  ASSERT_EQ(u16_expNCodeChars, cls->GetNCodeChars());
  ASSERT_EQ(u16_expNMemChars, cls->GetNMemoryChars());
  ASSERT_EQ(abs(u16_expNCodeChars - u16_expNMemChars), cls->GetNCharsDiff());

  ASSERT_EQ(u16_expNInfChars, cls->GetNCodeInflatedRepr());
  ASSERT_EQ(abs(u16_expNInfChars - u16_expNCodeChars), cls->GetNCodeInflReprDiff());

  cls->Reset();
  ASSERT_EQ(0, cls->GetNCodeChars());
  ASSERT_EQ(0, cls->GetNMemoryChars());
  ASSERT_EQ(0, cls->GetNCharsDiff());
  ASSERT_EQ(0, cls->GetNCodeInflatedRepr());
  ASSERT_EQ(0, cls->GetNCodeInflReprDiff());
}

TEST(ReverseEncoderTests, SanityTests) {

  auto target = ReverseEncoder();

  AssertStringBytes(&target, R"("")", 2, 0, 6);
  AssertStringBytes(&target, R"("abc")", 5, 3, 9);
  AssertStringBytes(&target, R"("aaa\"aaa")", 10, 7, 16);
  AssertStringBytes(&target, R"("\x27")", 6, 1, 11);

  target.ProcessString(R"("")");
  target.ProcessString(R"("abc")");
  target.ProcessString(R"("aaa\"aaa")");
  target.ProcessString(R"("\x27")");

  ASSERT_EQ(23, target.GetNCodeChars());
  ASSERT_EQ(11, target.GetNMemoryChars());
  ASSERT_EQ(12, target.GetNCharsDiff());
  ASSERT_EQ(42, target.GetNCodeInflatedRepr());
}

TEST(ReverseEncoderTests, KnownInputTests) {

  std::ifstream file("../../../2015/test/day8/test_data.in.txt");
  std::string str_line;

  auto target = ReverseEncoder();

  while(getline(file, str_line)) {
    target.ProcessString(str_line);
  }

  std::cout << "Code chars: " << target.GetNCodeChars() << std::endl;
  std::cout << "Memory chars: " << target.GetNMemoryChars() << std::endl;
  std::cout << "Difference: " << target.GetNCharsDiff() << std::endl << std::endl;

  std::cout << "Inflated representation chars: " << target.GetNCodeInflatedRepr() << std::endl;
  std::cout << "Difference: " << target.GetNCodeInflReprDiff() << std::endl << std::endl;
}