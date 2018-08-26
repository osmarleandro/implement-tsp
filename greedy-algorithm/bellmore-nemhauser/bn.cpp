#include <list>
using std::list;

#include <algorithm>
using std::find;

#include <limits>
using std::numeric_limits;

#include <iostream>
using std::size_t;

int nearestNeighbor(double **adj, int dimension, list<int> path, int city)
{
  int bestNeighbor = numeric_limits<int>::infinity();
  double bestCost = numeric_limits<double>::infinity();

  list<int>::iterator pathIterator = path.begin();
  for (size_t i = 1; i <= dimension; i++)
  {
    bool visited = find(path.begin(), path.end(), city) != path.end();
    if (visited == 0 && (city != i))
    {
      double neighborCost = adj[i][city];
      if (neighborCost <= bestCost)
      {
        bestNeighbor = i;
        bestCost = neighborCost;
      }
    }
  }
  return bestNeighbor;
}

list<int> solveNextNearestEdge(double **adj, int dimension, int start)
{
  list<int> path;
  path.push_back(start);
  size_t iteration = 1;

  while (iteration < dimension)
  {

    int beginEdge = *path.begin();
    int endEdge = *path.end();

    int bestBeginNeighbor = nearestNeighbor(adj, dimension, path, beginEdge);
    int bestEndNeighbor = nearestNeighbor(adj, dimension, path, endEdge);

    double costNeighborBegin = adj[beginEdge][bestBeginNeighbor];
    double costNeighborEnd = adj[endEdge][bestEndNeighbor];

    if (costNeighborEnd <= costNeighborBegin)
      path.push_back(bestEndNeighbor);

    else
      path.push_front(bestBeginNeighbor);

    iteration++;
  }

  return path;
}