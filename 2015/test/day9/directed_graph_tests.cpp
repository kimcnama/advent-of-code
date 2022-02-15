//
// Created by kieran McNamara on 14/02/2022.
//

#include <gtest/gtest.h>
#include "../../inc/day9/directed_graph.h"

TEST(DirectedGraphTests, SanityTests) {

  auto target = DirectedGraph();
  target.AddEdgeNode("London", "Dublin", 464);
  target.AddEdgeNode("London", "Belfast", 518);
  target.AddEdgeNode("Dublin", "Belfast", 141);

  target.PrintGraph();

  ASSERT_EQ(target.GetWeightBetweenNodes("London", "Dublin"), 464);
  ASSERT_EQ(target.GetWeightBetweenNodes("Dublin", "London"), 464);

  ASSERT_EQ(target.GetWeightBetweenNodes("Belfast", "London"), 518);
  ASSERT_EQ(target.GetWeightBetweenNodes("London", "Belfast"), 518);

  ASSERT_EQ(target.GetWeightBetweenNodes("Belfast", "Dublin"), 141);
  ASSERT_EQ(target.GetWeightBetweenNodes("Dublin", "Belfast"), 141);

  ASSERT_EQ(target.GetWeightBetweenNodes("Dublin", "Bet"), -1);
  ASSERT_EQ(target.GetWeightBetweenNodes("G", "Dublin"), -1);
}