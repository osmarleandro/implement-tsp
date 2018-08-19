#include "rdata.h"
#include <time.h>

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <algorithm>
using std::copy;
using std::find;
using std::next_permutation;
using std::sort;

#include <limits>
using std::numeric_limits;

double timeExecution(clock_t startTime);
void see(double **matrix, int dimension);
void see(int *vector, int dimension);
double cost(int *path, int dimension, double **matrix);

int *greedy(double **adj, int dimension, int start);
int bestNeighbor(double **adj, int dimension, int *path, int city);
bool visited(const int *begin, const int *end, int city);
int *brute_force(double **adj, int n, int *currentSolution);

int main(int argc, char **argv)
{
  double **matrixAdj;
  int dimension;
  int startCity = 1;

  // Reading the data of instance passed by parameter
  readData(argc, argv, &dimension, &matrixAdj);

  // Starting greedy algorithm looking for the best neighbor
  clock_t startTimeGreedy = clock();
  int *path = greedy(matrixAdj, dimension, startCity);
  double totalTime = timeExecution(startTimeGreedy);

  see(path, dimension);
  double totalCost = cost(path, dimension, matrixAdj);

  // Show the solution path
  cout << "The total cost of path was " << totalCost << endl;
  cout << "Tempo de execução: " << totalTime << " s" << endl;

  clock_t startTimeBrute = clock();
  int *bestPath = brute_force(matrixAdj, dimension, path);
  totalTime = timeExecution(startTimeBrute);

  double bestCost = cost(bestPath, dimension, matrixAdj);
  cout << "The best cost of path is " << bestCost << endl;
  cout << "Tempo de execução: " << totalTime << " s" << endl;

  // Deallocate memory
  delete[] matrixAdj, path;
  return 0;
}

double timeExecution(clock_t startTime)
{
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void see(double **matrix, int dimension)
{
  cout << "The Matrix of " << dimension << " dimensions" << endl;
  for (size_t i = 1; i <= dimension; i++)
  {
    for (size_t j = 1; j <= dimension; j++)
      cout << matrix[i][j] << "\t";
    cout << endl;
  }
}

void see(int *vector, int dimension)
{
  cout << "The path of " << dimension << " cities" << endl;
  for (size_t i = 0; i < dimension; i++)
  {
    cout << i + 1 << ": " << vector[i] << "    ";
    if (((i + 1) % 10) == 0)
      cout << "\n";
  }
  cout << endl;
}

double cost(int *path, int dimension, double **matrix)
{
  double totalCost = 0;
  for (size_t i = 0; i < dimension - 1; i++)
    totalCost = totalCost + matrix[path[i]][path[i + 1]];

  // Add symmetric cost of last city to first city
  totalCost = totalCost + matrix[path[0]][path[dimension - 1]];
  return totalCost;
}

int *greedy(double **adj, int dimension, int start)
{
  int *path = new int[dimension];
  path[0] = start;

  for (size_t i = 1; i < dimension; i++)
    path[i] = bestNeighbor(adj, dimension, path, path[i - 1]);

  return path;
}

/** 
 * For the best neighbor search, use the infinity neighbor 
 * as a comparison parameter for the others.
 * */
int bestNeighbor(double **adj, int dimension, int *path, int city)
{
  double bestNeighbor = numeric_limits<double>::infinity();
  double bestCost = numeric_limits<double>::infinity();

  for (size_t i = 1; i <= dimension; i++)
  {
    if (visited(path, path + dimension, i) == 0 && (city != i))
    {
      double neighborCost = adj[city][i];
      if (neighborCost <= bestCost)
      {
        bestNeighbor = i;
        bestCost = neighborCost;
      }
    }
  }
  return bestNeighbor;
}

bool visited(const int *begin, const int *end, int city)
{
  return find(begin, end, city) != end;
}

int *brute_force(double **adj, int n, int *bestSol)
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