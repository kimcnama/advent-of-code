//
// Created by kieran McNamara on 28/11/2021.
//

#ifndef ADVENTOFCODE_GIFT_WRAP_DIM_H
#define ADVENTOFCODE_GIFT_WRAP_DIM_H

#include <cstdint>
#include <vector>

class GiftWrapDim {

public:
    GiftWrapDim();
    GiftWrapDim(uint32_t u32_length, uint32_t u32_width, uint32_t u32_height);

    virtual void SetParams(uint32_t u32_length, uint32_t u32_width, uint32_t u32_height);
    uint32_t GetWrappingReq();
    ~GiftWrapDim();

protected:
    uint32_t u32_length_;
    uint32_t u32_width_;
    uint32_t u32_height_;
    uint32_t u32_wrappingRequired_;
    uint32_t u32_spareWrappingRequired_;
    std::vector<uint32_t> vec_faces_;
};

#endif //ADVENTOFCODE_GIFT_WRAP_DIM_H
