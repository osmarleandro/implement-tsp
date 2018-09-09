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
  while (iterations++ < dimension)
  {
    double cost, bCost = numeric_limits<double>::infinity();
    list<int>::iterator i, j, bIter;
    int bInsertion;
    // iteration at the current route
    for (i = route.begin(); i != route.end(); i++)
    {
      // if iterator j points to end, your element *j is the begin
      j = next(i, 1);
      j == route.end() ? ++j : j;

      // iteration at the cities list
      for (size_t k = 1; k <= dimension; k++)
      {
        // if the k city was visited, continue to next city
        bool visited = find(route.begin(), route.end(), k) != route.end();
        if (visited) continue;

        // if the current cost is more expensive than best, continue
        cost = adj[*i][k] + adj[k][*j] - adj[*i][*j];
        if (cost > bCost) continue;

        // if the iterator j points to begin, use the iterator i
        bCost = cost;
        bInsertion = k;
        bIter = j;
      }
    }
    // if the iterator points to begin, return to end for insert
    bIter == route.begin() ? --bIter : bIter;
    route.insert(bIter, bInsertion);
  }
  // Converting list to array
  return listToArray(route);
}