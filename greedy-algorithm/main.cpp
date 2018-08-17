#include "rdata.h"

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

void see(double **matrix, int n);
void see(int *vector, int n);

int *greedy(double **adj, int dimension, int start);
int bestNeighbor(double **adj, int dimension, int *path, int city);
bool visited(const int *begin, const int *end, int city);

int main(int argc, char **argv)
{

  double **matrixAdj;
  int dimension;

  readData(argc, argv, &dimension, &matrixAdj);
  see(matrixAdj, dimension);

  int startCity = 14;
  int *path = greedy(matrixAdj, dimension, startCity);
  see(path, dimension);

  // Deallocate memory
  delete[] matrixAdj, path;
  return 0;
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
  for (int i = 0; i < dimension; i++)
    cout << vector[i] << "\t";
  cout << endl;
}

int *greedy(double **adj, int dimension, int start)
{
  int *path = new int[dimension];
  path[0] = start;

  for (size_t i = 1; i < dimension; i++)
    path[i] = bestNeighbor(adj, dimension, path, path[i - 1]);

  return path;
}

/* For the best neighbor search, use the first neighbor 
  * as a comparison parameter for the others. 
  * */
int bestNeighbor(double **adj, int dimension, int *path, int city)
{
  double bestNeighbor = INFINITY;
  double bestCost = INFINITY;

  for (size_t i = 1; i <= dimension; i++)
  {
    if (visited(path, path + dimension, i) == 0 && (city != i))
    {
      int neighborCost = adj[city][i];
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