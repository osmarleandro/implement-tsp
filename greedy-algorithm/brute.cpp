#include <iostream>
using std::cout;
using std::endl;
using std::size_t;

#include <algorithm>
using std::copy;
using std::next_permutation;
using std::sort;

class BruteForce
{
    double cost(int *path, int dimension, double **matrix)
    {
        double totalCost = 0;
        for (size_t i = 0; i < dimension - 1; i++)
            totalCost = totalCost + matrix[path[i]][path[i + 1]];

        // Add symmetric cost of last city to first city
        totalCost = totalCost + matrix[path[0]][path[dimension - 1]];
        return totalCost;
    }

    int *solve(double **adj, int n, int *bestSol)
    {
        double iter = 1;
        double bestCost = cost(bestSol, n, adj);

        int *current = new int[n];
        copy(bestSol, bestSol + n, current);
        sort(current, current + n);

        while (next_permutation(current, current + n))
        {
            // calculing cost of current solution for next permutation
            double currentCost = cost(current, n, adj);
            if (currentCost < bestCost)
            {
                copy(current, current + n, bestSol);
                bestCost = currentCost;
            }
            iter++;
        };
        cout << "Iterations: " << iter << endl;
        return bestSol;
    }
}
