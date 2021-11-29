//
// Created by kieran McNamara on 28/11/2021.
//

#ifndef ADVENTOFCODE_WRAPPING_ORDER_H
#define ADVENTOFCODE_WRAPPING_ORDER_H

#include <vector>
#include <cstdint>
#include "gift_wrap_dim.h"

class WrappingOrder {
public:
    WrappingOrder();
    ~WrappingOrder();
    void AddOrder(uint32_t u32_length, uint32_t u32_width, uint32_t u32_height);
    void CalcWrappingPaperReq();
    uint32_t GetWrappingPaperReq();

private:
    std::vector<GiftWrapDim> vec_presents_;
    uint32_t u32_wrappingPaperReq_;
};

#endif //ADVENTOFCODE_WRAPPING_ORDER_H
