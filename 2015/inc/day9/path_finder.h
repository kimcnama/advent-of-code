//
// Created by kieran McNamara on 14/02/2022.
//

#ifndef ADVENTOFCODE_2015_INC_DAY9_PATH_FINDER_H_
#define ADVENTOFCODE_2015_INC_DAY9_PATH_FINDER_H_

#include "directed_graph.h"

class PathFinder : DirectedGraph {
 public:
  PathFinder();
  void AddEdgeStringFormat(const std::string& str_line);
  void PrintGraph();
  ~PathFinder();
 protected:

};

#endif //ADVENTOFCODE_2015_INC_DAY9_PATH_FINDER_H_
