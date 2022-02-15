//
// Created by kieran McNamara on 14/02/2022.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day9/directed_graph.h"
#include "../../inc/day9/path_finder.h"

static void AssertGraphEdges(PathFinder* cls, const std::string& src, const std::string& dst, int i_exp) {
  ASSERT_EQ(cls->GetWeightBetweenNodes(src, dst), i_exp);
  ASSERT_EQ(cls->GetWeightBetweenNodes(dst, src), i_exp);
}

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

  AssertGraphEdges(&target, "London", "Dublin", 464);
  AssertGraphEdges(&target, "London", "Belfast", 518);
  AssertGraphEdges(&target, "Dublin", "Belfast", 141);

  ASSERT_EQ(target.GetShortestPathLen(), 605);
}

TEST(PathFinderTests, GraphEdgeInputTests) {
  std::ifstream file("../../../2015/test/day9/test_data.in.txt");
  std::string str_line;

  auto target = PathFinder();

  while(getline(file, str_line)) {
    target.AddEdgeStringFormat(str_line);
  }

  AssertGraphEdges(&target, "Faerun", "Norrath", 129);
  AssertGraphEdges(&target, "Faerun", "Tristram", 58);
  AssertGraphEdges(&target, "Faerun", "AlphaCentauri", 13);
  AssertGraphEdges(&target, "Faerun", "Arbre", 24);
  AssertGraphEdges(&target, "Faerun", "Snowdin", 60);
  AssertGraphEdges(&target, "Faerun", "Tambi", 71);
  AssertGraphEdges(&target, "Faerun", "Straylight", 67);
  AssertGraphEdges(&target, "Norrath", "Tristram", 142);
  AssertGraphEdges(&target, "Norrath", "AlphaCentauri", 15);
  AssertGraphEdges(&target, "Norrath", "Arbre", 135);
  AssertGraphEdges(&target, "Norrath", "Snowdin", 75);
  AssertGraphEdges(&target, "Norrath", "Tambi", 82);
  AssertGraphEdges(&target, "Norrath", "Straylight", 54);
  AssertGraphEdges(&target, "Tristram", "AlphaCentauri", 118);
  AssertGraphEdges(&target, "Tristram", "Arbre", 122);
  AssertGraphEdges(&target, "Tristram", "Snowdin", 103);
  AssertGraphEdges(&target, "Tristram", "Tambi", 49);
  AssertGraphEdges(&target, "Tristram", "Straylight", 97);
  AssertGraphEdges(&target, "AlphaCentauri", "Arbre", 116);
  AssertGraphEdges(&target, "AlphaCentauri", "Snowdin", 12);
  AssertGraphEdges(&target, "AlphaCentauri", "Tambi", 18);
  AssertGraphEdges(&target, "AlphaCentauri", "Straylight", 91);
  AssertGraphEdges(&target, "Arbre", "Snowdin", 129);
  AssertGraphEdges(&target, "Arbre", "Tambi", 53);
  AssertGraphEdges(&target, "Arbre", "Straylight", 40);
  AssertGraphEdges(&target, "Snowdin", "Tambi", 15);
  AssertGraphEdges(&target, "Snowdin", "Straylight", 99);
  AssertGraphEdges(&target, "Tambi", "Straylight", 70);
}

TEST(PathFinderTests, InputTests) {

  std::ifstream file("../../../2015/test/day9/test_data.in.txt");
  std::string str_line;

  auto target = PathFinder();

  while(getline(file, str_line)) {
    target.AddEdgeStringFormat(str_line);
  }

  target.ProcessShortestPath();

  target.PrintShortestPath();

  ASSERT_EQ(target.GetShortestPathLen(), 207);
}
