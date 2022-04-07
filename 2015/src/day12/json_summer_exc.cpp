//
// Created by Kieran McNamara on 07/04/2022.
//

#include "../../inc/day12/json_summer_exc.h"

#define CHAR_OPEN_OBJ       ('{')
#define CHAR_CLOSE_OBJ      ('}')
#define CHAR_OPEN_ARR       ('[')
#define CHAR_CLOSE_ARR      (']')
#define CHAR_MINUS          ('-')

JsonSummerExc::JsonSummerExc(const std::string& str_exc) {
    this->_str_exception = str_exc;
    this->_str_json = "{}";
    this->i32_totSum = 0;
}

void JsonSummerExc::SetExceptionString(const std::string &str_exc) {
    this->_str_exception = str_exc;
}

void JsonSummerExc::SetJson(const std::string &str_json) {
    this->_str_json = str_json;
}

JsonSummerExc::~JsonSummerExc() = default;

int JsonSummerExc::GetJsonSum() {
    return this->i32_totSum;
}

void JsonSummerExc::ProcessJson() {
    std::string str_json = std::string(this->_str_json);
    this->i32_totSum = 0;
    this->RecursiveSum(&str_json);
}


static bool IsExcObjInCurrObj(const std::string& str_obj, const std::string& str_exc, uint32_t curr_i, bool b_backCount) {

    uint32_t u32_objI;
    for (uint32_t i = 0; i < str_exc.size(); ++i) {

        if (b_backCount) {
            u32_objI = curr_i + i;
        } else {
            u32_objI = curr_i - str_exc.size() + 1 + i;
        }

        if ( str_exc.at(i) != str_obj.at(u32_objI) ) {
            return false;
        }
    }

    return true;
}


void JsonSummerExc::RecursiveSum(std::string *ptr_str) {

    // If empty JSON
    if (ptr_str->size() < 3) {
        return;
    }

    bool b_currObjIsArray = ptr_str->at(0) == CHAR_OPEN_ARR &&
            ptr_str->at(ptr_str->size() - 1) == CHAR_CLOSE_ARR;

    uint32_t u16_firstChildObjOpenI = 0;
    uint32_t u16_firstChildObjCloseI = ptr_str->size() - 1;
    bool b_childObjOpenFound = false;
    bool b_childObjCloseFound = false;
    bool b_excStringInCurrObj = false;

    uint32_t u16_backCounter;
    for (uint32_t u32_i = 1; u32_i < ptr_str->size(); ++u32_i) {

        u16_backCounter = ptr_str->size() - u32_i - 1;
        if (u32_i >= this->_str_exception.size() - 1 && !b_currObjIsArray) {
            if (!b_childObjOpenFound) {
                b_excStringInCurrObj |=
                        IsExcObjInCurrObj(*ptr_str, this->_str_exception, u32_i, false);
            }
            if (!b_childObjCloseFound) {
                b_excStringInCurrObj |=
                        IsExcObjInCurrObj(*ptr_str, this->_str_exception, u16_backCounter, true);
            }
        }

        if (b_excStringInCurrObj) {
            return;
        }

        if (ptr_str->at(u32_i) == CHAR_OPEN_OBJ && !b_childObjOpenFound ) {
            u16_firstChildObjOpenI = u32_i;
            b_childObjOpenFound = true;
        }

        if ( ptr_str->at(u16_backCounter) == CHAR_CLOSE_OBJ && !b_childObjCloseFound ) {
            u16_firstChildObjCloseI = u16_backCounter;
            b_childObjCloseFound = true;
        }

        if (b_childObjOpenFound && b_childObjCloseFound) {
            break;
        }
    }

    if (b_childObjOpenFound && b_childObjCloseFound) {
        std::string sub_str = ptr_str->substr(u16_firstChildObjOpenI, u16_firstChildObjCloseI - u16_firstChildObjOpenI);
        RecursiveSum(&sub_str);
        ptr_str->erase(u16_firstChildObjOpenI, u16_firstChildObjCloseI - u16_firstChildObjOpenI + 1);
    }

    // recursive call for json objects above, now sum current object appropriately
    JsonSummer::ProcessJson(*ptr_str);
    this->i32_totSum += _i32_sum;
}

