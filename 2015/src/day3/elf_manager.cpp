//
// Created by kieran McNamara on 30/11/2021.
//

#include "../../inc/day3/elf_manager.h"

ElfManager::ElfManager() {
    santa_ = GridTraverserSub();
    roboSanta_ = GridTraverserSub();
    u32_nHousesRecPresents_ = 0;
}

uint32_t ElfManager::GetNumHousesRecPresents() {
    return u32_nHousesRecPresents_;
}

void ElfManager::ProcessListInstructions(std::string str_instructions) {

    int32_t i32_santaX = 0, i32_santaY = 0;
    int32_t i32_roboSantaX = 0, i32_roboSantaY = 0;

    santa_.UpdateInternalFromInstruction(i32_santaX, i32_santaY);
    roboSanta_.UpdateInternalFromInstruction(i32_roboSantaX, i32_roboSantaY);

    uint32_t u32_i = 0;
    for(const auto &ch : str_instructions) {
        switch(ch) {
            case '^':
                if (u32_i % 2 == 0) {
                    ++i32_santaY;
                } else {
                    ++i32_roboSantaY;
                }
                break;
            case 'v':
                if (u32_i % 2 == 0) {
                    --i32_santaY;
                } else {
                    --i32_roboSantaY;
                }
                break;
            case '>':
                if (u32_i % 2 == 0) {
                    ++i32_santaX;
                } else {
                    ++i32_roboSantaX;
                }
                break;
            case '<':
                if (u32_i % 2 == 0) {
                    --i32_santaX;
                } else {
                    --i32_roboSantaX;
                }
                break;
            default:
                continue;
        }
        santa_.UpdateInternalFromInstruction(i32_santaX, i32_santaY);
        roboSanta_.UpdateInternalFromInstruction(i32_roboSantaX, i32_roboSantaY);
        ++u32_i;
    }

    u32_nHousesRecPresents_ = 0;
    for(auto str_houseVisited : santa_.GetHousesVisited()) {
        ++u32_nHousesRecPresents_;
    }

    std::vector<std::string> vec_santaVisited = santa_.GetHousesVisited();

    for (const auto& str_houseVisited : roboSanta_.GetHousesVisited()) {
        if (std::count(vec_santaVisited.begin(), vec_santaVisited.end(), str_houseVisited) == 0) {
            ++u32_nHousesRecPresents_;
        }
    }
}

void ElfManager::ResetState() {
    santa_.ResetState();
    roboSanta_.ResetState();
    u32_nHousesRecPresents_ = 0;
}

ElfManager::~ElfManager() = default;
