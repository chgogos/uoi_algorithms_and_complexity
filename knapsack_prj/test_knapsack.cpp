#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "knapsack.hpp"

TEST_CASE("LOAD INSTANCE", "[classic]")
{
    string fn = "problem_10_50_1_1_5.txt";
    knapsack_problem ks = read_data(fn);
    REQUIRE(ks.items.size() == 10);
    REQUIRE(ks.capacity == 51);
}
