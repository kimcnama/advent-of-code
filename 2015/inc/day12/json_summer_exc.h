//
// Created by Kieran McNamara on 07/04/2022.
//

#ifndef ADVENTOFCODE_JSON_SUMMER_EXC_H
#define ADVENTOFCODE_JSON_SUMMER_EXC_H

#include <cstdint>
#include <string>
#include "json_summer.h"

class JsonSummerExc : JsonSummer {
public:
    JsonSummerExc(const std::string& str_exc);
    void SetExceptionString(const std::string& str_exc);
    void SetJson(const std::string& str_json);
    ~JsonSummerExc();
    void ProcessJson();
    int GetJsonSum();

protected:
    void RecursiveSum(std::string* ptr_str);

    std::string _str_exception;
    std::string _str_json;
    int i32_totSum;
};

#endif //ADVENTOFCODE_JSON_SUMMER_EXC_H
