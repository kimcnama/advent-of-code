//
// Created by kieran McNamara on 30/11/2021.
//

#include <string>
#include "../../inc/day3/grid_traverser_sub.h"

GridTraverserSub::GridTraverserSub() : GridTraverser() {}

std::vector<std::string> GridTraverserSub::GetHousesVisited() {
    std::vector<std::string> vec_housesVisited;

    vec_housesVisited.clear();
    for (const auto & [key, val] : map_housesPresents_) {
        vec_housesVisited.push_back(key);
    }
    return vec_housesVisited;
}

GridTraverserSub::~GridTraverserSub() = default;
