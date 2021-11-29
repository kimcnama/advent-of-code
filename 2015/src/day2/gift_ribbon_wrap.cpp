//
// Created by kieran McNamara on 29/11/2021.
//

#include "../../inc/day2/gift_ribbon_wrap.h"

GiftRibbonWrapped::GiftRibbonWrapped() : GiftWrapDim() {
    vec_edges_.clear();
    u32_volume_ = 0;
    u32_ribbonPerimeter_ = 0;
    u32_ribbonReq_ = 0;
}

GiftRibbonWrapped::GiftRibbonWrapped(uint32_t u32_length, uint32_t u32_width, uint32_t u32_height) {
    SetParams(u32_length, u32_width, u32_height);
}

uint32_t GiftRibbonWrapped::GetRibbonReq() {
    return u32_ribbonReq_;
}

void GiftRibbonWrapped::SetParams(uint32_t u32_length, uint32_t u32_width,
                                  uint32_t u32_height) {
    GiftWrapDim::SetParams(u32_length, u32_width, u32_height);

    vec_edges_.clear();
    vec_edges_.push_back(u32_length_);
    vec_edges_.push_back(u32_width_);
    vec_edges_.push_back(u32_height_);

    u32_volume_ = 0;
    u32_ribbonPerimeter_ = 0;
    for (auto &edge : vec_edges_) {
        if (u32_volume_ == 0) {
            u32_volume_ = 1;
        }
        u32_volume_ *= edge;
        u32_ribbonPerimeter_ += edge;
    }
    u32_ribbonPerimeter_ -= *std::max_element(vec_edges_.begin(), vec_edges_.end());
    u32_ribbonPerimeter_ = u32_ribbonPerimeter_ * 2;
    u32_ribbonReq_ = u32_ribbonPerimeter_ + u32_volume_;
}

GiftRibbonWrapped::~GiftRibbonWrapped() = default;
