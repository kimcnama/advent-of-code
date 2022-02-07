//
// Created by kieran McNamara on 29/11/2021.
//

#include <string>
#include "../../inc/day3/grid_traverser.h"

GridTraverser::GridTraverser() {
    i32_startX_ = 0;
    i32_startY_ = 0;
    u32_numHousesRecPresents_ = 0;
    u32_numPresentsDelivered_ = 0;
    map_housesPresents_.clear();
}

GridTraverser::GridTraverser(int32_t i32_startX, int32_t i32_startY) {
    i32_startX_ = i32_startX;
    i32_startY_ = i32_startY;
    u32_numHousesRecPresents_ = 0;
    u32_numPresentsDelivered_ = 0;
    map_housesPresents_.clear();
}


void GridTraverser::ResetState() {
    u32_numHousesRecPresents_ = 0;
    u32_numPresentsDelivered_ = 0;
    map_housesPresents_.clear();
}


std::string GridTraverser::GetKeyString(int32_t i32_x, int32_t i32_y) {
    std::string str_x = std::to_string(i32_x);
    std::string str_y = std::to_string(i32_y);
    return str_x + "_" + str_y;
}



void GridTraverser::ProcessInstructions(const std::string& str_instructions) {

    if (str_instructions.length() < 1) {
        return;
    }

    int32_t i32_currX = i32_startX_;
    int32_t i32_currY = i32_startY_;

    GridTraverser::UpdateInternalFromInstruction(i32_currX, i32_currY);

    for(const auto &ch : str_instructions) {
        switch(ch) {
            case '^':
                ++i32_currY;
                break;
            case 'v':
                --i32_currY;
                break;
            case '>':
                ++i32_currX;
                break;
            case '<':
                --i32_currX;
                break;
            default:
                continue;
        }
        GridTraverser::UpdateInternalFromInstruction(i32_currX, i32_currY);
    }

}

void GridTraverser::UpdateInternalFromInstruction(int32_t i32_x, int32_t i32_y) {
    std::string str_currHouseKey;
    str_currHouseKey = GridTraverser::GetKeyString(i32_x, i32_y);

    ++u32_numPresentsDelivered_;

    bool b_dictContainsKey = false;
    for(auto & [key, value] : map_housesPresents_) {
        if (str_currHouseKey == key) {
            ++value;
            b_dictContainsKey = true;
            break;
        }
    }

    if(!b_dictContainsKey) {
        map_housesPresents_[str_currHouseKey] = 1;
        ++u32_numHousesRecPresents_;
    }
}

uint32_t GridTraverser::GetNumPresentsDelivered() {
    return u32_numPresentsDelivered_;
}

uint32_t GridTraverser::GetNumHousesRecPresents() {
    return u32_numHousesRecPresents_;
}

GridTraverser::~GridTraverser() = default;
