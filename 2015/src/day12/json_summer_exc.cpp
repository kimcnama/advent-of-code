//
// Created by Kieran McNamara on 07/04/2022.
//

#include "../../inc/day12/json_summer_exc.h"

#define CHAR_OPEN_OBJ       ('{')
#define CHAR_CLOSE_OBJ      ('}')
#define CHAR_OPEN_ARR       ('[')
#define CHAR_CLOSE_ARR      (']')


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

// Given index of start of obj, find end index of current obj, excluding its children
static uint32_t FindCloseEndDelimIndex(const std::string& str_obj, const uint32_t curr_i, bool b_isObj) {

    uint32_t u32_stackCounter = 0;
    char ch_endDelim, ch_startDelim;
    if ( b_isObj ) {
        ch_startDelim = CHAR_OPEN_OBJ;
        ch_endDelim = CHAR_CLOSE_OBJ;
    } else {
        ch_startDelim = CHAR_OPEN_ARR;
        ch_endDelim = CHAR_CLOSE_ARR;
    }

    for (uint32_t i = curr_i + 1; i < str_obj.size(); ++i) {

        if ( str_obj.at(i) == ch_endDelim ) {

            if ( u32_stackCounter == 0 ) {
                return i;
            } else {
                --u32_stackCounter;
            }

        } else if ( str_obj.at(i) == ch_startDelim ) {
            ++u32_stackCounter;
        }

    }
    return str_obj.size() - 1;
}

// Checks if illegal substr in current obj (ignoring its children)
static bool IsExcStrInCurrObj(const std::string& str_obj, const std::string& str_exc) {

    bool b_doesContainSubstr;
    char ch_obj, ch_exc;
    for (uint32_t i = 1; i < str_obj.size() - str_exc.size(); ++i) {

        ch_obj = str_obj.at(i);

        if ( ch_obj == CHAR_OPEN_ARR ) {
            i = FindCloseEndDelimIndex(str_obj, i, false);
        } else if ( ch_obj == CHAR_OPEN_OBJ ) {
            i = FindCloseEndDelimIndex(str_obj, i, true);
        }

        b_doesContainSubstr = true;
        for (uint32_t j = 0; j < str_exc.size(); ++j) {
            ch_obj = str_obj.at(i + j);
            ch_exc = str_exc.at(j);
            if ( ch_exc != ch_obj ) {
                b_doesContainSubstr = false;
                break;
            }
        }
        if (b_doesContainSubstr) {
            return true;
        }
    }

    return false;
}


// Func to keep sum of numbers in json, recursively calling itself for its children objects
void JsonSummerExc::RecursiveSum(std::string *ptr_str) {

    // If empty JSON or array
    if (ptr_str->size() < 3) {
        return;
    }

    // If current object is array, than can ignore checks later where we ignore obj if contains red
    bool b_currObjIsArray = ptr_str->at(0) == CHAR_OPEN_ARR &&
                            ptr_str->at(ptr_str->size() - 1) == CHAR_CLOSE_ARR;

    // If exception string in current object (ignoring children objects) than return and do not add to sum
    if (!b_currObjIsArray && IsExcStrInCurrObj(*ptr_str, this->_str_exception)) {
        return;
    }

    uint32_t u32_childOpenI, u32_childCloseI;
    uint32_t u32_strLen = ptr_str->size();
    uint32_t u32_i = 1;

    while (u32_i < u32_strLen) {

        // If found start of first child object
        if (ptr_str->at(u32_i) == CHAR_OPEN_OBJ || ptr_str->at(u32_i) == CHAR_OPEN_ARR ) {

            // Get start index of child obj and find end index of child obj
            u32_childOpenI = u32_i;
            u32_childCloseI = FindCloseEndDelimIndex(*ptr_str, u32_i, ptr_str->at(u32_i) == CHAR_OPEN_OBJ);

            // Get substr of child obj and pass into recursive func
            std::string sub_str = ptr_str->substr(u32_childOpenI, u32_childCloseI - u32_childOpenI + 1);
            this->RecursiveSum(&sub_str);

            // erase child object from current object as sum is handled in recursive call
            ptr_str->erase(u32_childOpenI, u32_childCloseI - u32_childOpenI + 1);
        }

        // Update length incase substr removed and update counter
        u32_strLen = ptr_str->size();
        ++u32_i;
    }

    // Now that child objects removed and object does not contain exception string, sum numbers in obj
    JsonSummer::ProcessJson(*ptr_str);
    this->i32_totSum += _i32_sum;
}


