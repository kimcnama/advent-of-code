//
// Created by kieran McNamara on 19/12/2021.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day7/wire.h"

TEST(WireTest, SanityTests) {
  auto x = Wire(123);
  ASSERT_EQ(x.GetSignalVal(), 123);

  auto y = Wire(456);
  ASSERT_EQ(y.GetSignalVal(), 456);

  auto d = Wire(0);
  auto e = Wire(0);
  auto f = Wire(0);
  auto g = Wire(0);
  auto h = Wire(0);
  auto i = Wire(0);

  d.And(&x, &y);
  e.Or(&x, &y);
  f.LShift(&x, 2);
  g.RShift(&y, 2);
  h.Not(&x);
  i.Not(&y);

  ASSERT_EQ(d.GetSignalVal(), 72);
  ASSERT_EQ(e.GetSignalVal(), 507);
  ASSERT_EQ(f.GetSignalVal(), 492);
  ASSERT_EQ(g.GetSignalVal(), 114);
  ASSERT_EQ(h.GetSignalVal(), 65412);
  ASSERT_EQ(i.GetSignalVal(), 65079);
  ASSERT_EQ(x.GetSignalVal(), 123);
  ASSERT_EQ(y.GetSignalVal(), 456);
}
