//
// Created by kieran McNamara on 14/02/2022.
//

#ifndef ADVENTOFCODE_2015_INC_DAY9_PATH_FINDER_H_
#define ADVENTOFCODE_2015_INC_DAY9_PATH_FINDER_H_

#include <vector>
#include "directed_graph.h"

class PathFinder : DirectedGraph {
 public:
  PathFinder();
  void AddEdgeStringFormat(const std::string& str_line);
  void PrintGraph();
  void ProcessShortestPath();
  void PrintShortestPath();
  void PrintLongestPath();
  ~PathFinder();
  int GetWeightBetweenNodes(const std::string &str_nodeName, const std::string &str_destNodeName);
  uint32_t GetShortestPathLen();
  uint32_t GetLongestPathLen();

 protected:
  void RecursivePathSearch(const std::string& str_travelToNode, uint32_t u32_dist);
  bool AllNodesVisited();

  std::vector<std::string> _vec_visited;
  std::vector<std::string> _vec_startVerticesVisited;
  std::vector<std::string> _vec_shortestPath;
  std::vector<std::string> _vec_longestPath;
  uint32_t _u32_currPathLen = 0;
  uint32_t _u32_shortestPathLen;
  uint32_t _u32_longestPathLen;
};

#endif //ADVENTOFCODE_2015_INC_DAY9_PATH_FINDER_H_
