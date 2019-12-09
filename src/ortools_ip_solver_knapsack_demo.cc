#include "../ortools/include/ortools/linear_solver/linear_solver.h"

namespace operations_research
{
void simple_knapsack_program()
{
    MPSolver solver("IP KNAPSACK SOLVER", MPSolver::CBC_MIXED_INTEGER_PROGRAMMING);
    const double infinity = solver.infinity();
    MPVariable *const x1 = solver.MakeBoolVar("x1");
    MPVariable *const x2 = solver.MakeBoolVar("x2");
    MPVariable *const x3 = solver.MakeBoolVar("x3");
    MPVariable *const x4 = solver.MakeBoolVar("x4");
    MPConstraint *const c = solver.MakeRowConstraint(0, 6.0, "capacity_constraint");
    c->SetCoefficient(x1, 4);
    c->SetCoefficient(x2, 3);
    c->SetCoefficient(x3, 2);
    c->SetCoefficient(x4, 3);
    MPObjective *const objective = solver.MutableObjective();
    objective->SetCoefficient(x1, 3);
    objective->SetCoefficient(x2, 2);
    objective->SetCoefficient(x3, 4);
    objective->SetCoefficient(x4, 4);
    objective->SetMaximization();
    solver.Solve();
    std::cout << "Objective value = " << objective->Value() << std::endl;
    std::cout << "x1 = " << x1->solution_value();
    std::cout << " x2 = " << x2->solution_value();
    std::cout << " x3 = " << x3->solution_value();
    std::cout << " x4 = " << x4->solution_value() << std::endl;
}
} // namespace operations_research

int main()
{
    operations_research::simple_knapsack_program();
    return EXIT_SUCCESS;
}