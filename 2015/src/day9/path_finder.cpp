//
// Created by kieran McNamara on 14/02/2022.
//

#include "../../inc/day9/path_finder.h"

#define DELIMITER_NODES   " to "
#define DELIMITER_EDGES   " = "

PathFinder::PathFinder() = default;

PathFinder::~PathFinder() = default;

void PathFinder::AddEdgeStringFormat(const std::string& str_line) {

  std::string str_source = str_line.substr(0, str_line.find_first_of(DELIMITER_NODES));
  std::string str_dest = str_line.substr(str_line.find_first_of(DELIMITER_NODES) + 1, str_line.find_first_of(DELIMITER_EDGES));
  std::string str_weight = str_line.substr(str_line.find_first_of(DELIMITER_EDGES) + 1);

  this->AddEdgeNode(str_source, str_dest, (uint32_t)atoi(str_weight.c_str()));
}
void PathFinder::PrintGraph() {
  DirectedGraph::PrintGraph();
}
