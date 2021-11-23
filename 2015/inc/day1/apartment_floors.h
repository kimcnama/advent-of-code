//
// Created by kieran McNamara on 23/11/2021.
//

#include <iostream>

#ifndef ADVENT_OF_CODE_APARTMENT_FLOORS_H
#define ADVENT_OF_CODE_APARTMENT_FLOORS_H

class Stack {
public:
    Stack();
    ~Stack();

    void SetStackString(std::string &s);
    std::string GetStackString();

    void AnalyseStackString();

    int GetStackBalance();
    int GetFirstBasementIndex();

    void PrintStackString();

private:
    int i32_balanceIndication_;
    std::string str_stack_;
    char ch_openChar_;
    char ch_closeChar_;
    int i32_firstCharBasementInd_;
};

#endif //ADVENT_OF_CODE_APARTMENT_FLOORS_H
