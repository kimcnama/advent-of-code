//
// Created by kieran McNamara on 16/12/2021.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day5/naughty_nice_string.h"

void PopulateExcStrings(NaughtNiceStrings* cls) {
  cls->AddExceptionString("ab");
  cls->AddExceptionString("cd");
  cls->AddExceptionString("pq");
  cls->AddExceptionString("xy");
}

TEST(DoesNotContainSubStr, Sanity) {
  auto cls = NaughtNiceStrings();
  PopulateExcStrings(&cls);

  cls.SetString("haegwjzuvuyypxyu");
  ASSERT_FALSE(cls.DoesExcludeExceptions());

  cls.SetString("ugknbfddgicrmopn");
  ASSERT_TRUE(cls.DoesExcludeExceptions());
}

TEST(ContainsTwoLetterInrow, Sanity) {
  auto cls = NaughtNiceStrings();
  PopulateExcStrings(&cls);

  cls.SetString("aabbccdd");
  ASSERT_TRUE(cls.ContainsDoubleLetter());

  cls.SetString("jchzalrnumimnmhp");
  ASSERT_FALSE(cls.ContainsDoubleLetter());
}

TEST(Contains3Vowels, Sanity) {
  auto cls = NaughtNiceStrings();
  PopulateExcStrings(&cls);

  cls.SetString("aei");
  ASSERT_TRUE(cls.AtLeast3Vowels());

  cls.SetString("aaa");
  ASSERT_TRUE(cls.AtLeast3Vowels());

  cls.SetString("xazegov");
  ASSERT_TRUE(cls.AtLeast3Vowels());

  cls.SetString("aeiouaeiouaeiou");
  ASSERT_TRUE(cls.AtLeast3Vowels());

  cls.SetString("dvszwmarrgswjxmb");
  ASSERT_FALSE(cls.AtLeast3Vowels());
}

TEST(IsNice, Sanity) {
  auto cls = NaughtNiceStrings();
  PopulateExcStrings(&cls);

  cls.SetString("ugknbfddgicrmopn");
  ASSERT_TRUE(cls.IsNiceString());

  cls.SetString("aaa");
  ASSERT_TRUE(cls.IsNiceString());

  cls.SetString("jchzalrnumimnmhp");
  ASSERT_FALSE(cls.IsNiceString());

  cls.SetString("haegwjzuvuyypxyu");
  ASSERT_FALSE(cls.IsNiceString());

  cls.SetString("dvszwmarrgswjxmb");
  ASSERT_FALSE(cls.IsNiceString());
}

TEST(Part1Test, KnownInut) {

  std::string str_inputInstructions;
  std::ifstream file("../../../2015/test/day5/test_data.in.txt");
  std::string str_line;

  auto cls = NaughtNiceStrings();
  PopulateExcStrings(&cls);

  uint16_t u16_niceStrCount = 0;

  while (getline(file, str_line)) {
    cls.SetString(str_line);
    if (cls.IsNiceString()) {
      ++u16_niceStrCount;
    }
  }
  std::cout << "Number of nice strings: " << u16_niceStrCount << std::endl;

  ASSERT_TRUE(u16_niceStrCount == 258);
}


