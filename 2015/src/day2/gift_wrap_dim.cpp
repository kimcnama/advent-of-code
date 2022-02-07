//
// Created by kieran McNamara on 28/11/2021.
//

#include "../../inc/day2/gift_wrap_dim.h"

GiftWrapDim::GiftWrapDim() {
    u32_length_ = 0;
    u32_width_ = 0;
    u32_height_ = 0;
    u32_wrappingRequired_ = 0;
    u32_spareWrappingRequired_ = 0;
    vec_faces_.clear();
};

GiftWrapDim::GiftWrapDim(uint32_t u32_length, uint32_t u32_width, uint32_t u32_height) {
    SetParams(u32_length, u32_width, u32_height);
}


void GiftWrapDim::SetParams(uint32_t u32_length, uint32_t u32_width, uint32_t u32_height) {
    u32_length_ = u32_length;
    u32_width_ = u32_width;
    u32_height_ = u32_height;

    vec_faces_.clear();
    vec_faces_.push_back(u32_length_ * u32_width_);
    vec_faces_.push_back(u32_width_ * u32_height_);
    vec_faces_.push_back(u32_height_ * u32_length_);

    u32_spareWrappingRequired_ = *std::min_element(vec_faces_.begin(), vec_faces_.end());
    u32_wrappingRequired_ = u32_spareWrappingRequired_;
    for (auto u32_face : vec_faces_) {
        u32_wrappingRequired_ += 2 * u32_face;
    }
}

uint32_t GiftWrapDim::GetWrappingReq() {
    return u32_wrappingRequired_;
}


GiftWrapDim::~GiftWrapDim() = default;

