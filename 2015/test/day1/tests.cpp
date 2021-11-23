//
// Created by kieran McNamara on 23/11/2021.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../../inc/day1/apartment_floors.h"

void SetAnalyseAndReturnBalance(Stack* stack, std::string str, int expectedVal) {
    stack->SetStackString(str);
    EXPECT_TRUE(stack->GetStackBalance() == 0);
    stack->AnalyseStackString();
    EXPECT_TRUE(stack->GetStackBalance() == expectedVal);
}

TEST(Day1Tests, Init) {
    auto* stack = new Stack();
    ASSERT_TRUE(stack != nullptr);
    EXPECT_TRUE(stack->GetStackBalance() == 0);
    EXPECT_TRUE(stack->GetStackString() == "");

    SetAnalyseAndReturnBalance(stack, "(())", 0);
    SetAnalyseAndReturnBalance(stack, "()()", 0);

    SetAnalyseAndReturnBalance(stack, "(((", 3);
    SetAnalyseAndReturnBalance(stack, "(()(()(", 3);

    SetAnalyseAndReturnBalance(stack, "))(((((", 3);

    SetAnalyseAndReturnBalance(stack, "())", -1);
    SetAnalyseAndReturnBalance(stack, "))(", -1);

    SetAnalyseAndReturnBalance(stack, ")))", -3);
    SetAnalyseAndReturnBalance(stack, ")())())", -3);

    delete stack;
}