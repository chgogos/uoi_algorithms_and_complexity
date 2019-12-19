#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct item
{
    int id;
    int profit;
    int weight;
};

struct knapsack_problem
{
    vector<item> items;
    int capacity;
    int time_limit = 10; // seconds
};

knapsack_problem read_data(string &fn)
{
    ifstream fin(fn);
    if (!fin.good())
    {
        cerr << "Error opening file " << fn << endl;
        exit(-1);
    }
    knapsack_problem ks;
    int items_number;
    fin >> items_number;
    for (int i = 0; i < items_number; i++)
    {
        item an_item;
        fin >> an_item.id;
        fin >> an_item.profit;
        fin >> an_item.weight;
        ks.items.push_back(an_item);
    }
    fin >> ks.capacity;
    return ks;
}

void print_knapsack_problem_info(knapsack_problem &ks)
{
    cout << "Items=" << ks.items.size() << std::endl;
    for (int i = 0; i < ks.items.size(); i++)
    {
        std::cout << "Item=" << ks.items[i].id << " value=" << ks.items[i].profit << " weight=" << ks.items[i].weight << std::endl;
    }
    std::cout << "Capacity=" << ks.capacity << std::endl;
}
