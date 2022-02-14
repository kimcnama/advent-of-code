//
// Created by kieran McNamara on 14/02/2022.
//

#include <c++/v1/vector>
#include "../../inc/day9/directed_graph.h"

DirectedGraph::DirectedGraph() = default;

static bool IsGraphEdgesEq(const GraphEdge* g1, const GraphEdge* g2) {
  if (g1->str_srcNode != g2->str_srcNode) {
    return false;
  }
  if (g1->str_destNode != g2->str_destNode) {
    return false;
  }
  return g1->u32_edgeWeight == g2->u32_edgeWeight;
}

void DirectedGraph::UpdateGraph(const std::string &str_nodeName, const std::string &str_destNodeName, uint32_t u32_edgeWeight) {

  GraphEdge graphEdge;
  graphEdge.str_srcNode = str_nodeName;
  graphEdge.str_destNode = str_destNodeName;
  graphEdge.u32_edgeWeight = u32_edgeWeight;

  bool b_nodeFound = false;
  bool b_containsEdge = false;

  for (auto & it : _map_graph) {
    if (it.first == str_nodeName) {
      b_nodeFound = true;

      for (auto & edge : it.second) {
        if (IsGraphEdgesEq(&edge, &graphEdge)) {
          b_containsEdge = true;
          break;
        }
      }

      if (!b_containsEdge) {
        it.second.push_back(graphEdge);
      }

    }
  }

  if (!b_nodeFound) {
    std::vector<GraphEdge> vec;
    vec.push_back(graphEdge);
    this->_map_graph.insert({str_nodeName, vec});
  }
}
void DirectedGraph::PrintGraph() {
  for (auto & it : _map_graph) {
    std::cout << "Node: " << it.first << " :: ";
    for (auto & edge : it.second) {
      std::cout << edge.str_destNode << "(" << edge.u32_edgeWeight  << ") ";
    }
    std::cout << std::endl;
  }
}
void DirectedGraph::AddEdgeNode(const std::string &str_nodeName,
                                const std::string &str_destNodeName,
                                uint32_t u32_edgeWeight) {
  this->UpdateGraph(str_nodeName, str_destNodeName, u32_edgeWeight);
  this->UpdateGraph(str_destNodeName, str_nodeName, u32_edgeWeight);
}

int DirectedGraph::GetWeightBetweenNodes(const std::string &str_nodeName, const std::string &str_destNodeName) {
  for (auto & it : _map_graph) {

    if (it.first == str_nodeName) {
      for (int i = 0; i < it.second.size(); ++i) {

        if (it.second.at(i).str_destNode == str_destNodeName) {
          return it.second.at(i).u32_edgeWeight;
        }

      }
    }

  }

  return -1;
}

DirectedGraph::~DirectedGraph() = default;
