#include <time.h>

#include <iostream>
using std::cout;
using std::endl;
using std::size_t;

#include <list>
using std::list;

#include <limits>
using std::numeric_limits;

#include <algorithm>
using std::copy;
using std::find;

int *listToArray(list<int> list)
{
  int *arr = new int[list.size()];
  copy(list.begin(), list.end(), arr);
  return arr;
}

int nearestNeighborEdge(double **adj, int dimension, list<int> path, int city)
{
  int bestNeighbor = numeric_limits<int>::infinity();
  double bestCost = numeric_limits<double>::infinity();

  for (size_t i = 1; i <= dimension; i++)
  {
    bool visited = find(path.begin(), path.end(), i) != path.end();
    if (visited == 0 && (city != i))
    {
      double neighborCost = adj[city][i];
      if (neighborCost <= bestCost && neighborCost > 0)
      {
        bestNeighbor = i;
        bestCost = neighborCost;
      }
    }
  }
  return bestNeighbor;
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
    cout << i + 1 << ": " << vector[i] << "\t";
    if (((i + 1) % 10) == 0)
      cout << "\n";
  }
  cout << endl;
}

void see(list<int> route, int dimension)
{
  see(listToArray(route), dimension);
}

double timeExecution(clock_t startTime)
{
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
