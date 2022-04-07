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

// Check if exception string starts or ends at current index
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

// Calls itself recursively everytime a child object is found
void JsonSummerExc::RecursiveSum(std::string *ptr_str) {

    // If empty JSON or array
    if (ptr_str->size() < 3) {
        return;
    }

    // If current object is array, than can ignore checks later where we ignore obj if contains red
    bool b_currObjIsArray = ptr_str->at(0) == CHAR_OPEN_ARR &&
            ptr_str->at(ptr_str->size() - 1) == CHAR_CLOSE_ARR;

    uint32_t u16_firstChildObjOpenI = 0;
    uint32_t u16_firstChildObjCloseI = ptr_str->size() - 1;
    bool b_childObjOpenFound = false;
    bool b_childObjCloseFound = false;
    bool b_excStringInCurrObj = false;

    // iterate backwards and forwards through array at same time
    // u16_backCounter is iterating backwards and u32_i forwards
    // Iterators starting at 1 and len - 2 (to ignore '{' and '}' chars of JSON)
    uint32_t u16_backCounter;
    for (uint32_t u32_i = 1; u32_i < ptr_str->size(); ++u32_i) {

        // get backwards iterator
        u16_backCounter = ptr_str->size() - u32_i - 1;

        // If long far enough into json, check is exception string starts or ends at curr indices
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

        // if exception string in object, return before count is done later
        if (b_excStringInCurrObj) {
            return;
        }

        // If found start of first child object, note index
        if (ptr_str->at(u32_i) == CHAR_OPEN_OBJ && !b_childObjOpenFound ) {
            u16_firstChildObjOpenI = u32_i;
            b_childObjOpenFound = true;
        }

        // If found end of first child object, note index
        if ( ptr_str->at(u16_backCounter) == CHAR_CLOSE_OBJ && !b_childObjCloseFound ) {
            u16_firstChildObjCloseI = u16_backCounter;
            b_childObjCloseFound = true;
        }

        // if start and end index found of child object, break and call func recursively with substr of those indices
        if (b_childObjOpenFound && b_childObjCloseFound) {
            break;
        }
    }

    // if child object found, call func recursively with child object
    if (b_childObjOpenFound && b_childObjCloseFound) {
        std::string sub_str = ptr_str->substr(u16_firstChildObjOpenI, u16_firstChildObjCloseI - u16_firstChildObjOpenI);
        RecursiveSum(&sub_str);

        // erase child object from current object as sum is handled in recursive call
        ptr_str->erase(u16_firstChildObjOpenI, u16_firstChildObjCloseI - u16_firstChildObjOpenI + 1);
    }

    // Now that child objects removed and object does not contain exception string, sum numbers in obj
    JsonSummer::ProcessJson(*ptr_str);
    this->i32_totSum += _i32_sum;
}

