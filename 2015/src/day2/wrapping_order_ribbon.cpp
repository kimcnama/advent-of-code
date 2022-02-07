//
// Created by kieran McNamara on 29/11/2021.
//

#include "../../inc/day2/wrapping_order_ribbon.h"

WrappingOrderRibbon::WrappingOrderRibbon() {
    vec_presents_.clear();
    u32_ribbonReq_ = 0;
}

WrappingOrderRibbon::~WrappingOrderRibbon() = default;

void WrappingOrderRibbon::AddOrder(uint32_t u32_length, uint32_t u32_width, uint32_t u32_height) {
    vec_presents_.push_back(GiftRibbonWrapped(u32_length, u32_width, u32_height));
}

void WrappingOrderRibbon::CalcRibbonReq() {
    u32_ribbonReq_ = 0;
    for(GiftRibbonWrapped present : vec_presents_) {
        u32_ribbonReq_ += present.GetRibbonReq();
    }
}

uint32_t WrappingOrderRibbon::GetRibbonReq() {
    return u32_ribbonReq_;
}

