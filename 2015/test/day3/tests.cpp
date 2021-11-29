//
// Created by kieran McNamara on 29/11/2021.
//

#include <gtest/gtest.h>
#include <fstream>
#include "../../inc/day3/grid_traverser.h"

TEST(GridTraverser, SanityTests) {
    auto traversal = GridTraverser();
    ASSERT_TRUE(traversal.GetNumHousesRecPresents() == 0);
    ASSERT_TRUE(traversal.GetNumPresentsDelivered() == 0);

    traversal.ProcessInstructions(">");
    ASSERT_TRUE(traversal.GetNumHousesRecPresents() == 2);

    traversal.ResetState();
    ASSERT_TRUE(traversal.GetNumHousesRecPresents() == 0);
    ASSERT_TRUE(traversal.GetNumPresentsDelivered() == 0);

    traversal.ProcessInstructions("^>v<");
    ASSERT_TRUE(traversal.GetNumHousesRecPresents() == 4);

    traversal.ResetState();
    ASSERT_TRUE(traversal.GetNumHousesRecPresents() == 0);
    ASSERT_TRUE(traversal.GetNumPresentsDelivered() == 0);

    traversal.ProcessInstructions("^v^v^v^v^v");
    ASSERT_TRUE(traversal.GetNumHousesRecPresents() == 2);
}

TEST(GridTraverser, InputTest) {
    std::string str_inputInstructions;
    std::ifstream file("../../../2015/test/day3/test_data.in.txt");
    std::string str_line;

    while (getline(file, str_line)) {
        if (str_inputInstructions.empty()) {
            str_inputInstructions = str_line;
        } else {
            str_inputInstructions += str_line;
        }
    }

    auto traversal = GridTraverser();
    ASSERT_TRUE(traversal.GetNumHousesRecPresents() == 0);
    ASSERT_TRUE(traversal.GetNumPresentsDelivered() == 0);

    traversal.ProcessInstructions(str_inputInstructions);
    std::cout << std::endl << "Number houses received presents: " << traversal.GetNumHousesRecPresents() << std::endl;

    ASSERT_TRUE(traversal.GetNumHousesRecPresents() == 2081);
}
