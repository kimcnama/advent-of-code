//
// Created by kieran McNamara on 14/02/2022.
//

#include <gtest/gtest.h>
#include "../../inc/day9/directed_graph.h"
#include "../../inc/day9/path_finder.h"

TEST(PathFinderTests, SanityTests) {

  std::string str_ins1 = "London to Dublin = 464";
  std::string str_ins2 = "London to Belfast = 518";
  std::string str_ins3 = "Dublin to Belfast = 141";

  auto target = PathFinder();

  target.AddEdgeStringFormat(str_ins1);
  target.AddEdgeStringFormat(str_ins2);
  target.AddEdgeStringFormat(str_ins3);

  target.PrintGraph();

  target.ProcessShortestPath();

  target.PrintShortestPath();
  auto x = 1;
}