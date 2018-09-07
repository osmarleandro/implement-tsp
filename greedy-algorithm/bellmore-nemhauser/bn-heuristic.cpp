#include <list>
using std::list;

#include <iostream>
using std::cout;
using std::size_t;

#include "../../util/common.h"

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