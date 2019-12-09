#include "../ortools/include/ortools/algorithms/knapsack_solver.h"

namespace operations_research
{
void KnapsackExample()
{
    KnapsackSolver solver(KnapsackSolver::KNAPSACK_DYNAMIC_PROGRAMMING_SOLVER,
                          "SimpleKnapsackExample");
    std::vector<int64> values = {3, 2, 4, 4};
    std::vector<std::vector<int64>> weights = {{4, 3, 2, 3}};
    std::vector<int64> capacities = {6};
    solver.Init(values, weights, capacities);
    int64 computed_value = solver.Solve();
    std::cout << "Total value: " << computed_value << std::endl;

    std::vector<int> packed_items;
    for (std::size_t i = 0; i < values.size(); ++i)
    {
        if (solver.BestSolutionContains(i))
            std::cout << "Item " << i + 1 << " is in the bag" << std::endl;
    }
}
} // namespace operations_research

int main()
{
    operations_research::KnapsackExample();
    return EXIT_SUCCESS;
}
