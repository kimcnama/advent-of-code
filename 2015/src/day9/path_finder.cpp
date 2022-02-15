//
// Created by kieran McNamara on 14/02/2022.
//

#include "../../inc/day9/path_finder.h"

#define DELIMITER_NODES   " to "
#define DELIMITER_EDGES   " = "
#define MAX_PATH_LEN      0xFFFFFFFF

PathFinder::PathFinder() {
  _u32_shortestPathLen = MAX_PATH_LEN;
  _u32_longestPathLen = 0;
};

PathFinder::~PathFinder() = default;

static bool VecContainsString(const std::vector<std::string>& v, const std::string& str) {
  return std::find(v.begin(), v.end(), str) != v.end();
}

void PathFinder::AddEdgeStringFormat(const std::string& str_line) {

  std::string str_source = str_line.substr(0, str_line.find(DELIMITER_NODES));
  std::string str_temp = str_line.substr(str_line.find(DELIMITER_NODES) + std::string(DELIMITER_NODES).size());

  std::string str_dest = str_temp.substr(0, str_temp.find(DELIMITER_EDGES));
  std::string str_weight = str_temp.substr(str_temp.find(DELIMITER_EDGES) + std::string(DELIMITER_EDGES).size());

  this->AddEdgeNode(str_source, str_dest, (uint32_t)atoi(str_weight.c_str()));
}
void PathFinder::PrintGraph() {
  DirectedGraph::PrintGraph();
}



void PathFinder::ProcessShortestPath() {

  _u32_shortestPathLen = MAX_PATH_LEN;
  _u32_longestPathLen = 0;

  for (auto & node : _map_graph) {

    if (VecContainsString(_vec_startVerticesVisited, node.first)) {
      continue;
    }

    _vec_startVerticesVisited.push_back(node.first);
    _vec_visited.clear();
    _u32_currPathLen = 0;

    this->RecursivePathSearch(node.first, 0);
  }

}

void PathFinder::RecursivePathSearch(const std::string& str_travelToNode, uint32_t u32_dist) {

  if (VecContainsString(_vec_visited, str_travelToNode)) {
    return;
  }

  _vec_visited.push_back(str_travelToNode);
  _u32_currPathLen += u32_dist;

  if (this->AllNodesVisited()) {

    if (_u32_currPathLen < _u32_shortestPathLen) {
      _u32_shortestPathLen = _u32_currPathLen;
      _vec_shortestPath.clear();
      for (auto & it : _vec_visited) {
        _vec_shortestPath.push_back(it);
      }
    }

    if (_u32_currPathLen > _u32_longestPathLen) {
      _u32_longestPathLen = _u32_currPathLen;
      _vec_longestPath.clear();
      for (auto & it : _vec_visited) {
        _vec_longestPath.push_back(it);
      }
    }
  }

  for (auto & node : _map_graph) {

    if (node.first == str_travelToNode) {
      for (auto & neighbour : node.second) {

        RecursivePathSearch(neighbour.str_destNode, neighbour.u32_edgeWeight);

      }
    }
  }
  _u32_currPathLen -= u32_dist;
  _vec_visited.pop_back();
}
bool PathFinder::AllNodesVisited() {
  for (auto & node : _map_graph) {

    if (!VecContainsString(_vec_visited, node.first)) {
      return false;
    }

  }
  return true;
}
void PathFinder::PrintShortestPath() {
  std::cout << std::endl;

  for (auto i = 0; i < this->_vec_shortestPath.size(); ++i) {

    std::cout << this->_vec_shortestPath.at(i);
    if (i < _vec_shortestPath.size() - 1) {
      std::cout << " -> ";
    } else {
      std::cout << " = ";
    }
  }
  std::cout << this->_u32_shortestPathLen << std::endl;
}

void PathFinder::PrintLongestPath() {
  std::cout << std::endl;

  for (auto i = 0; i < this->_vec_longestPath.size(); ++i) {

    std::cout << this->_vec_longestPath.at(i);
    if (i < _vec_longestPath.size() - 1) {
      std::cout << " -> ";
    } else {
      std::cout << " = ";
    }
  }
  std::cout << this->_u32_longestPathLen << std::endl;
}

int PathFinder::GetWeightBetweenNodes(const std::string &str_nodeName, const std::string &str_destNodeName) {
  return DirectedGraph::GetWeightBetweenNodes(str_nodeName, str_destNodeName);
}
uint32_t PathFinder::GetShortestPathLen() {
  return this->_u32_shortestPathLen;
}
uint32_t PathFinder::GetLongestPathLen() {
  return this->_u32_longestPathLen;
}
