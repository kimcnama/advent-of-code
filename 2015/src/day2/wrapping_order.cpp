//
// Created by kieran McNamara on 28/11/2021.
//

#include "../../inc/day2/wrapping_order.h"

WrappingOrder::WrappingOrder() {
    vec_presents_.clear();
    u32_wrappingPaperReq_ = 0;
}

void WrappingOrder::AddOrder(uint32_t u32_length, uint32_t u32_width, uint32_t u32_height) {
    vec_presents_.push_back(GiftWrapDim(u32_length, u32_width, u32_height));
}

WrappingOrder::~WrappingOrder() = default;

void WrappingOrder::CalcWrappingPaperReq() {
    u32_wrappingPaperReq_ = 0;
    for(GiftWrapDim present : vec_presents_) {
        u32_wrappingPaperReq_ += present.GetWrappingReq();
    }
}

uint32_t WrappingOrder::GetWrappingPaperReq() {
    return u32_wrappingPaperReq_;
}

