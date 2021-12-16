//
// Created by kieran McNamara on 16/12/2021.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day5/naughty_nice_string_part2.h"

TEST(ContainsDuo, Sanity) {

  auto cls = NaughtNiceStrings2();

  cls.SetString("xyxy");
  ASSERT_TRUE(cls.ContainsDuo());

  cls.SetString("aabcdefgaa");
  ASSERT_TRUE(cls.ContainsDuo());

  cls.SetString("xxbblkas");
  ASSERT_FALSE(cls.ContainsDuo());

  cls.SetString("lkasxxbb");
  ASSERT_FALSE(cls.ContainsDuo());

  cls.SetString("aaa");
  ASSERT_FALSE(cls.ContainsDuo());

  cls.SetString("ieodomkazucvgmuy");
  ASSERT_FALSE(cls.ContainsDuo());

  cls.SetString("uurcxstgmygtbstg");
  ASSERT_TRUE(cls.ContainsDuo());
}

TEST(RecurringCharDuo, Sanity) {

  auto cls = NaughtNiceStrings2();

  cls.SetString("xyx");
  ASSERT_TRUE(cls.HasReccuringCharWithDelim());

  cls.SetString("xxyxx");
  ASSERT_TRUE(cls.HasReccuringCharWithDelim());

  cls.SetString("abcdefeghi");
  ASSERT_TRUE(cls.HasReccuringCharWithDelim());

  cls.SetString("aaa");
  ASSERT_TRUE(cls.HasReccuringCharWithDelim());

  cls.SetString("uurcxstgmygtbstg");
  ASSERT_FALSE(cls.HasReccuringCharWithDelim());

  cls.SetString("ieodomkazucvgmuy");
  ASSERT_TRUE(cls.HasReccuringCharWithDelim());
}

TEST(IsNiceTests, Sanity) {

  auto cls = NaughtNiceStrings2();

  cls.SetString("qjhvhtzxzqqjkmpb");
  ASSERT_TRUE(cls.IsNiceString());

  cls.SetString("xxyxx");
  ASSERT_TRUE(cls.IsNiceString());

  cls.SetString("uurcxstgmygtbstg");
  ASSERT_FALSE(cls.IsNiceString());

  cls.SetString("ieodomkazucvgmuy");
  ASSERT_FALSE(cls.IsNiceString());

}

TEST(Part2Test, KnownInut) {

  std::string str_inputInstructions;
  std::ifstream file("../../../2015/test/day5/test_data.in.txt");
  std::string str_line;

  auto cls = NaughtNiceStrings2();

  uint16_t u16_niceStrCount = 0;
  uint16_t u16_lines = 0;

  while (getline(file, str_line)) {
    cls.SetString(str_line);
    if (cls.IsNiceString()) {
      ++u16_niceStrCount;
    } else {
      cls.IsNiceString();
    }
    ++u16_lines;
  }
  std::cout << "Number of nice strings: " << u16_niceStrCount << std::endl;
  std::cout << "Number of lines: " << u16_lines << std::endl;

  ASSERT_TRUE(u16_niceStrCount == 258);
}