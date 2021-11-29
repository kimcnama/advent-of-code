//
// Created by kieran McNamara on 29/11/2021.
//

#ifndef ADVENTOFCODE_GIFT_RIBBON_WRAP_H
#define ADVENTOFCODE_GIFT_RIBBON_WRAP_H

#include "gift_wrap_dim.h"

class GiftRibbonWrapped : public GiftWrapDim {
public:
    GiftRibbonWrapped();
    GiftRibbonWrapped(uint32_t u32_length, uint32_t u32_width, uint32_t u32_height);
    void SetParams(uint32_t u32_length, uint32_t u32_width, uint32_t u32_height);
    uint32_t GetRibbonReq();
    ~GiftRibbonWrapped();

protected:
    uint32_t u32_volume_;
    std::vector<uint32_t> vec_edges_;
    uint32_t u32_ribbonPerimeter_;
    uint32_t u32_ribbonReq_;
};

#endif //ADVENTOFCODE_GIFT_RIBBON_WRAP_H
