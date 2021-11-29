//
// Created by kieran McNamara on 29/11/2021.
//

#ifndef ADVENTOFCODE_WRAPPING_ORDER_RIBBON_H
#define ADVENTOFCODE_WRAPPING_ORDER_RIBBON_H

#include <vector>
#include <cstdint>
#include "gift_ribbon_wrap.h"

class WrappingOrderRibbon {

public:
    WrappingOrderRibbon();
    ~WrappingOrderRibbon();
    void AddOrder(uint32_t u32_length, uint32_t u32_width, uint32_t u32_height);
    void CalcRibbonReq();
    uint32_t GetRibbonReq();

private:
    std::vector<GiftRibbonWrapped> vec_presents_;
    uint32_t u32_ribbonReq_;
};

#endif //ADVENTOFCODE_WRAPPING_ORDER_RIBBON_H
