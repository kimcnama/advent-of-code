//
// Created by kieran McNamara on 10/02/2022.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day8/character_memory_service.h"

static void AssertStringBytes(CharacterMemoryService* cls,const std::string& str, const uint16_t& u16_expNCodeChars,
    const uint16_t& u16_expNMemChars) {

  cls->ProcessString(str);
  ASSERT_EQ(u16_expNCodeChars, cls->GetNCodeChars());
  ASSERT_EQ(u16_expNMemChars, cls->GetNMemoryChars());
  ASSERT_EQ(abs(u16_expNCodeChars - u16_expNMemChars), cls->GetNCharsDiff());
  cls->Reset();
  ASSERT_EQ(0, cls->GetNCodeChars());
  ASSERT_EQ(0, cls->GetNMemoryChars());
  ASSERT_EQ(0, cls->GetNCharsDiff());
}

TEST(CharacterMemoryServiceTests, SanityTests) {

  auto target = CharacterMemoryService();

  AssertStringBytes(&target, R"("")", 2, 0);
  AssertStringBytes(&target, R"("abc")", 5, 3);
  AssertStringBytes(&target, R"("aaa\"aaa")", 10, 7);
  AssertStringBytes(&target, R"("\x27")", 6, 1);

  target.ProcessString(R"("")");
  target.ProcessString(R"("abc")");
  target.ProcessString(R"("aaa\"aaa")");
  target.ProcessString(R"("\x27")");

  ASSERT_EQ(23, target.GetNCodeChars());
  ASSERT_EQ(11, target.GetNMemoryChars());
  ASSERT_EQ(12, target.GetNCharsDiff());
}




