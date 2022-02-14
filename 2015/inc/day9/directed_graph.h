//
// Created by kieran McNamara on 14/02/2022.
//

#ifndef ADVENTOFCODE_2015_INC_DAY9_DIRECTED_GRAPH_H_
#define ADVENTOFCODE_2015_INC_DAY9_DIRECTED_GRAPH_H_

#include <iostream>
#include <map>

struct GraphEdge {
  std::string str_srcNode;
  std::string str_destNode;
  uint32_t u32_edgeWeight;
};

class DirectedGraph {
 public:
  DirectedGraph();
  ~DirectedGraph();
  void AddEdgeNode(const std::string &str_nodeName, const std::string &str_destNodeName, uint32_t u32_edgeWeight);
  void PrintGraph();
 protected:
  void UpdateGraph(const std::string &str_nodeName, const std::string &str_destNodeName, uint32_t u32_edgeWeight);

  std::map<std::string, std::vector<GraphEdge>> _map_graph;
};

#endif //ADVENTOFCODE_2015_INC_DAY9_DIRECTED_GRAPH_H_
