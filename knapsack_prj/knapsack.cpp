#include "knapsack.hpp"

int main()
{
    string fn = "problem_10_50_1_1_5.txt";
    knapsack_problem ks = read_data(fn);
    print_knapsack_problem_info(ks);
}