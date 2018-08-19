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
using std::find;

#include <limits>
using std::numeric_limits;

void timeExecution(clock_t startTime);
void see(double **matrix, int dimension);
void see(int *vector, int dimension);
void seeCost(int *path, int dimension, double **matrix);

int *greedy(double **adj, int dimension, int start);
int bestNeighbor(double **adj, int dimension, int *path, int city);
bool visited(const int *begin, const int *end, int city);

int main(int argc, char **argv)
{
  double **matrixAdj;
  int dimension;

  // Reading the data of instance passed by parameter
  readData(argc, argv, &dimension, &matrixAdj);

  int startCity = 666;
  clock_t tStart = clock();
  int *path = greedy(matrixAdj, dimension, startCity);

  // Show the solution path
  see(path, dimension);
  seeCost(path, dimension, matrixAdj);
  timeExecution(tStart);

  // Deallocate memory
  delete[] matrixAdj, path;
  return 0;
}

void timeExecution(clock_t startTime)
{
  cout << "Tempo de execução: " << (double)(clock() - startTime) / CLOCKS_PER_SEC << " s" << endl;
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

void seeCost(int *path, int dimension, double **matrix)
{
  double totalCost = 0;
  for (size_t i = 0; i < dimension - 1; i++)
    totalCost = totalCost + matrix[path[i]][path[i + 1]];

  // Add symmetric cost of last city to first city
  totalCost = totalCost + matrix[path[0]][path[dimension - 1]];
  cout << "The total cost of path was " << totalCost << endl;
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