#include "../../util/common.h"

#include <list>
using std::list;

#include <algorithm>
using std::copy;
using std::find;

#include <limits>
using std::numeric_limits;

#include <iterator>
using std::next;

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
  int iterations = 2;

  // iterate while exists city to evalue
  while (iterations++ <= dimension)
  {
    double cost, bCost = numeric_limits<double>::infinity();
    list<int>::iterator i, j, bIter;
    int bInsertion;

    // iteration at the current route
    for (i = route.begin(); i != route.end(); ++i)
    {
      j = next(i, 1);
      // iteration at the cities list
      for (size_t k = 1; k <= dimension; k++)
      {
        bool visited = find(route.begin(), route.end(), k) != route.end();
        if (visited) continue;

        cost = adj[*i][k] + adj[k][*j] - adj[*i][*j];
        if (cost > bCost) continue;

        bCost = cost;
        bIter = j;
      }
    }
    route.insert(bIter, *bIter);
  }
  // Converting list to array
  return listToArray(route);
}