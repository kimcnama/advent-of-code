//
// Created by Kieran McNamara on 08/04/2022.
//

#include <gtest/gtest.h>
#include "../../inc/day13/seating_arranger.h"

TEST(JsonSummerTests, SanityTest) {
    auto target = SeatingArranger();

    target.AddEdge("Alice", "Bob", 54);
    target.AddEdge("Alice", "Carol", -79);
    target.AddEdge("Alice", "David", -2);
    target.AddEdge("Bob", "Alice", 83);
    target.AddEdge("Bob", "Carol", -7);
    target.AddEdge("Bob", "David", -63);
    target.AddEdge("Carol", "Alice", -62);
    target.AddEdge("Carol", "Bob", 60);
    target.AddEdge("Carol", "David", 55);
    target.AddEdge("David", "Alice", 46);
    target.AddEdge("David", "Bob", -7);
    target.AddEdge("David", "Carol", 41);

    target.PrintMap();
}