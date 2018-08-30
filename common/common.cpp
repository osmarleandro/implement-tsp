#include <iostream>
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
  int bestNeighbor = numeric_limits<double>::infinity();
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
