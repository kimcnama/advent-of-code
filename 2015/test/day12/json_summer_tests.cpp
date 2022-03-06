//
// Created by kieran McNamara on 06/03/2022.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day12/json_summer.h"

TEST(JsonSummerTests, SanityTest) {

  auto target = JsonSummer();

  target.ProcessJson("[1,2,3]");
  ASSERT_EQ(target.GetSum(), 6);
  target.ProcessJson(R"({"a":2,"b":4})");
  ASSERT_EQ(target.GetSum(), 6);

  target.ProcessJson("[[[3]]]");
  ASSERT_EQ(target.GetSum(), 3);
  target.ProcessJson(R"({"a":{"b":4},"c":-1})");
  ASSERT_EQ(target.GetSum(), 3);

  target.ProcessJson("{\"a\":[-1,1]}");
  ASSERT_EQ(target.GetSum(), 0);
  target.ProcessJson(R"([-1,{"a":1}])");
  ASSERT_EQ(target.GetSum(), 0);
}

TEST(JsonSummerTests, KnownInputTest) {

  auto target = JsonSummer();

  std::ifstream file("../../../2015/test/day12/test_data.in.txt");
  std::string str_line;

  while(getline(file, str_line)) {
    target.ProcessJson(str_line);
  }

  ASSERT_EQ(target.GetSum(), 111754);
}
