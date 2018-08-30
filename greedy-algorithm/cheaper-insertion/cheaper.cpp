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

#include "../../common/common.h"

list<int> generateSubroute(double **adj, int dimension, int start)
{
  list<int> subroute;
  subroute.push_back(start);

  int nearest = nearestNeighborEdge(adj, dimension, subroute, start);
  subroute.push_back(nearest);

  return subroute;
}

int *cheaperInsertion(double **adj, int dimension, int start)
{
  list<int> route = generateSubroute(adj, dimension, start);
  size_t iteration = 1;

  while (iteration++ < dimension)
  {
    int beginEdge = route.front();
    int endEdge = route.back();

    int bestBeginNeighbor = nearestNeighborEdge(adj, dimension, route, beginEdge);
    int bestEndNeighbor = nearestNeighborEdge(adj, dimension, route, endEdge);

    double costNeighborBegin = adj[beginEdge][bestBeginNeighbor];
    double costNeighborEnd = adj[endEdge][bestEndNeighbor];

    if (costNeighborEnd <= costNeighborBegin)
      route.push_back(bestEndNeighbor);

    else
      route.push_front(bestBeginNeighbor);
  }
  // Converting list to array
  return listToArray(route);
}