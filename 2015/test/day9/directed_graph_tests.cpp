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

}