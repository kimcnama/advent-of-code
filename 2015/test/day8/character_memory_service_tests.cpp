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

TEST(WireManagerTest, SanityTests) {

  auto target = CharacterMemoryService();

  AssertStringBytes(&target, "\"\"", 2, 0);
  AssertStringBytes(&target, "\"abc\"", 5, 3);
}