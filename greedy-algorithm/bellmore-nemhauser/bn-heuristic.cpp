#include <list>
using std::list;

#include <algorithm>
using std::copy;
using std::find;

#include <limits>
using std::numeric_limits;

#include <iostream>
using std::cout;
using std::size_t;

#include <iterator>
using std::copy;

int nearestNeighborEdge(double **adj, int dimension, list<int> path, int city)
{
  double bestNeighbor = numeric_limits<double>::infinity();
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

int *solveNearestEdge(double **adj, int dimension, int start)
{
  list<int> path;
  path.push_back(start);
  size_t iteration = 1;

  while (iteration++ < dimension)
  {
    int beginEdge = path.front();
    int endEdge = path.back();

    int bestBeginNeighbor = nearestNeighborEdge(adj, dimension, path, beginEdge);
    int bestEndNeighbor = nearestNeighborEdge(adj, dimension, path, endEdge);

    double costNeighborBegin = adj[beginEdge][bestBeginNeighbor];
    double costNeighborEnd = adj[endEdge][bestEndNeighbor];

    if (costNeighborEnd <= costNeighborBegin)
      path.push_back(bestEndNeighbor);

    else
      path.push_front(bestBeginNeighbor);
  }
  // Converting list to array
  int *bnPath = new int[path.size()];
  copy(path.begin(), path.end(), bnPath);
  return bnPath;
}