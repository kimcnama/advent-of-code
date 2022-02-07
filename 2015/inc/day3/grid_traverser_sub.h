//
// Created by kieran McNamara on 30/11/2021.
//

#ifndef ADVENTOFCODE_GRID_TRAVERSER_SUB_H
#define ADVENTOFCODE_GRID_TRAVERSER_SUB_H

#include "grid_traverser.h"

class GridTraverserSub : public GridTraverser {

public:
    GridTraverserSub();
    ~GridTraverserSub();
    std::vector<std::string> GetHousesVisited();
};

#endif //ADVENTOFCODE_GRID_TRAVERSER_SUB_H
