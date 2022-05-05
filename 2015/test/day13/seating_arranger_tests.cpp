//
// Created by Kieran McNamara on 08/04/2022.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day13/seating_arranger.h"

#define SUBSTR_SEARCH           " happiness units by sitting next to "
#define POSITIVE_HAPPINESS_STR  "gain "
#define NEGATIVE_HAPPINESS_STR  "lose "

static void ParseStringLineAndAddEdge(SeatingArranger* target, const std::string& str_line) {
    bool b_isPositive;
    int i32_happiness;
    std::string guest1 = str_line.substr(0, str_line.find_first_of(' '));

    std::size_t temppos = str_line.find(SUBSTR_SEARCH) + std::string(SUBSTR_SEARCH).size();
    std::string str_temp = str_line.substr(temppos);
    std::string guest2 = str_temp.substr(0, str_temp.find_first_of('.'));

    temppos = str_line.find(SUBSTR_SEARCH);
    str_temp = str_line.substr(0, temppos);
    if (str_temp.find(POSITIVE_HAPPINESS_STR) != std::string::npos) {
        b_isPositive = true;
        temppos = str_line.find(POSITIVE_HAPPINESS_STR) + std::string(POSITIVE_HAPPINESS_STR).size();
        str_temp = str_temp.substr(temppos);
    } else {
        b_isPositive = false;
        temppos = str_line.find(NEGATIVE_HAPPINESS_STR) + std::string(NEGATIVE_HAPPINESS_STR).size();
        str_temp = str_temp.substr(temppos);
    }

    i32_happiness = std::stoi(str_temp);
    target->AddEdge(guest1, guest2, b_isPositive ? i32_happiness : -i32_happiness);
}

TEST(JsonSummerTests, SanityTest) {
    auto target = SeatingArranger();

    target.AddEdge("Carol", "Alice", -62);
    target.AddEdge("Carol", "Bob", 60);
    target.AddEdge("Carol", "David", 55);
    target.AddEdge("David", "Alice", 46);
    target.AddEdge("David", "Bob", -7);
    target.AddEdge("David", "Carol", 41);
    target.AddEdge("Alice", "Bob", 54);
    target.AddEdge("Alice", "Carol", -79);
    target.AddEdge("Alice", "David", -2);
    target.AddEdge("Bob", "Alice", 83);
    target.AddEdge("Bob", "Carol", -7);
    target.AddEdge("Bob", "David", -63);

    target.PrintMap();
    target.ProcessArrangements();
    std::cout << "Optimal Arrangment: " << target.GetOptimalArrangementScore();
}

TEST(JsonSummerTests, KnownInputTest) {

    auto target = SeatingArranger();

    std::ifstream file("../../../2015/test/day13/test_data.in.txt");
    std::string str_line;

    while(getline(file, str_line)) {
        ParseStringLineAndAddEdge(&target, str_line);
    }
    target.PrintMap();
    target.ProcessArrangements();
    std::cout << "Optimal Arrangment: " << target.GetOptimalArrangementScore();
}