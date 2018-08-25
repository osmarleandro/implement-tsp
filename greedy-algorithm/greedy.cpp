#include <algorithm>
using std::find;

#include <limits>
using std::numeric_limits;

bool visited(const int *begin, const int *end, int city)
{
  return find(begin, end, city) != end;
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

/** 
 * This algorithm search the best neighbor of the current city, 
 * then make next until the last city.
 * */
int *greedy(double **adj, int dimension, int start)
{
  int *path = new int[dimension];
  path[0] = start;

  for (size_t i = 1; i < dimension; i++)
    path[i] = bestNeighbor(adj, dimension, path, path[i - 1]);

  return path;
}