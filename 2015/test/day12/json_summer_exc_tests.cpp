//
// Created by Kieran McNamara on 07/04/2022.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day12/json_summer_exc.h"

static void TestJson(JsonSummerExc* target, const std::string& str_json, int i32_exp) {
    target->SetJson(str_json);
    target->ProcessJson();
    ASSERT_EQ(target->GetJsonSum(), i32_exp);
}

TEST(JsonSummerExcTests, SanityTest) {
    auto target = JsonSummerExc("red");

    TestJson(&target, "[1,2,3]", 6);
    TestJson(&target, R"([1,{"c":"red","b":2},3])", 4);
    TestJson(&target, R"({"d":"red","e":[1,2,3,4],"f":5})", 0);
    TestJson(&target, R"([1,"red",5])", 6);
}