//
// Created by kieran McNamara on 23/11/2021.
//

#include "../../inc/day1/apartment_floors.h"

#include <utility>


Stack::Stack() {
    i32_balanceIndication_ = 0;
    str_stack_ = "";
    ch_openChar_ = '(';
    ch_closeChar_ = ')';
}

Stack::~Stack() = default;

void Stack::SetStackString(std::string &s) {
    str_stack_ = s;
    i32_balanceIndication_ = 0;
}

std::string Stack::GetStackString() {
    return str_stack_;
}

void Stack::AnalyseStackString() {
    for(char const &c: str_stack_) {
        if (c == ch_openChar_) {
            ++i32_balanceIndication_;
        } else if (c == ch_closeChar_) {
            --i32_balanceIndication_;
        }
    }
}

int Stack::GetStackBalance() {
    return i32_balanceIndication_;
}

void Stack::PrintStackString() {
    for(char const &c: str_stack_) {
        std::cout << c << " ";
    }
}


