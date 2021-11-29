//
// Created by kieran McNamara on 29/11/2021.
//

#ifndef ADVENTOFCODE_GRID_TRAVERSER_H
#define ADVENTOFCODE_GRID_TRAVERSER_H

#include <cstdint>
#include <vector>
#include <map>

class GridTraverser {

public:
    GridTraverser();
    GridTraverser(int32_t i32_startX, int32_t i32_startY);
    void ResetState();
    void ProcessInstructions(const std::string& str_instructions);
    uint32_t GetNumHousesRecPresents();
    uint32_t GetNumPresentsDelivered();
    void UpdateInternalFromInstruction(int32_t i32_x, int32_t i32_y);
    ~GridTraverser();

protected:
    static std::string GetKeyString(int32_t i32_x, int32_t i32_y);

    int32_t i32_startX_;
    int32_t i32_startY_;
    uint32_t u32_numHousesRecPresents_;
    uint32_t u32_numPresentsDelivered_;
    std::map<std::string, uint32_t> map_housesPresents_;
};

#endif //ADVENTOFCODE_GRID_TRAVERSER_H
