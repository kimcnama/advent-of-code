//
// Created by kieran McNamara on 23/11/2021.
//

#include "../../inc/day1/apartment_floors.h"
#include <utility>

Stack::Stack() {
    i32_balanceIndication_ = 0;
    i32_firstCharBasementInd_ = 1;
    str_stack_ = "";
    ch_openChar_ = '(';
    ch_closeChar_ = ')';
}

Stack::~Stack() = default;

void Stack::SetStackString(std::string &s) {
    str_stack_ = s;
    i32_balanceIndication_ = 0;
    i32_firstCharBasementInd_ = 0;
}

std::string Stack::GetStackString() {
    return str_stack_;
}

void Stack::AnalyseStackString() {
    int i = 0;
    bool b_haveReachedBasement = false;
    for(char const &c: str_stack_) {
        ++i;
        if (c == ch_openChar_) {
            ++i32_balanceIndication_;
        } else if (c == ch_closeChar_) {
            --i32_balanceIndication_;
        }

        if (i32_balanceIndication_ < 0 && !b_haveReachedBasement) {
            b_haveReachedBasement = true;
            i32_firstCharBasementInd_ = i;
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

int Stack::GetFirstBasementIndex() {
    return i32_firstCharBasementInd_;
}


