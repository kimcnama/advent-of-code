//
// Created by kieran McNamara on 30/11/2021.
//

#ifndef ADVENTOFCODE_ELF_MANAGER_H
#define ADVENTOFCODE_ELF_MANAGER_H

#include <cstdint>
#include <iostream>
#include "grid_traverser_sub.h"

class ElfManager {
public:
    ElfManager();
    ~ElfManager();
    uint32_t GetNumHousesRecPresents();
    void ResetState();
    void ProcessListInstructions(std::string);

private:
    uint32_t u32_nHousesRecPresents_;
    GridTraverserSub santa_;
    GridTraverserSub roboSanta_;
};

#endif //ADVENTOFCODE_ELF_MANAGER_H
